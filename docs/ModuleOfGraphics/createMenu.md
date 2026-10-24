# Создание окна внутри другого процесса и корректное завершение dll-файла

### 🔍 Шаг 1. Прощупывание "почвы" для дальнейшей работы
Перед тем как писать код, сначала нужно разобраться в двух важных системных функциях, которые предоставляет OpenGL.

1. wglSwapBuffers - главная системная функция для отрисовки игры, которая сигнализирует, что закончила строить 3D-сцену текущего кадра и готова вывести её пользователю.
2. wndProc - функция для обработки сообщений, которые отправляет Windows окну игры.

---

### 🕵️‍♂️ Шаг 2. Анализ найденных функций
Для начала рассмотрим хук-функцию hk_WglSwapBuffers

```cpp
BOOL __stdcall hk_WglSwapBuffers(HDC hdc) {
    // Флаг для корректного закрытия dll-файла при отгрузке, чтобы в последние моменты жизни файла возвращались настоящие данные функции, а не наши подменённые
    if (unloadingFromGame) return o_WglSwapBuffers(hdc); 
    
    static bool imguiInit = false;
  
    if (!imguiInit) { // Срабатывает один раз при подключении dll-файла благодаря static-переменной "imguiInit"!
      gameHwnd = WindowFromDC(hdc); // Получим дескриптор окна-приложения и присвоим в переменную
      ImGui::CreateContext(); // Создаёт новый глобальный контекст с пользовательским интерфейсом
      ImGui_ImplWin32_Init(gameHwnd); // Привязка окна игры с дескриптором к OC Windows для отслеживания мыши, клавиатуры и другого
      ImGui_ImplOpenGL2_Init(); // Инициализации графического бэкенда OpenGL 2.0 для библиотеки ImGui
  
      Gui::Menu::menuManager.UploadTabs();
  
      imguiInit = true;
    }
  
    if (!Settings::configSettings.menuOpen) {
      unloadingFromGame = true;
  
      RequestShutdown();
  
      return o_WglSwapBuffers(hdc);
    }
  
    ImGui_ImplOpenGL2_NewFrame(); // Подготовка графического движка к работе
    ImGui_ImplWin32_NewFrame(); // Для сбора нажатий и кликов Windows
    ImGui::NewFrame(); // Функция, которая открывает (начинает) новый кадр логики интерфейса для процесса приложения
  
    Gui::Menu::menuManager.DrawMainWindow(); 
  
    ImGui::Render(); // Функция, которая завершает формирование кадра и формирует его геометрический чертёж
    ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData()); // Функция, которая физически рисует пиксели интерфейса на экране
  
    return o_WglSwapBuffers(hdc);
}
```
---
```cpp
LRESULT CALLBACK hk_WndProc(HWND hWnd, UINT uInt, WPARAM wParam, LPARAM lParam) {
    if (unloadingFromGame) return CallWindowProc(o_WndProc, hWnd, uInt, wParam, lParam);

    // ImGui_ImplWin32_WndProcHandler - функция Dear ImGui, которая отвечает за перехват, расшифровку и обработку всех системных сообщений от мыши и клавиатуры в операционной системе Windows
    if (Settings::configSettings.menuOpen && ImGui_ImplWin32_WndProcHandler(hWnd, uInt, wParam, lParam)) {
        return true; // Если мы кликнули по меню или пишем в него текст — «съедаем» клик. Игра о нем не узнает.
    }

    return CallWindowProc(o_WndProc, hWnd, uInt, wParam, lParam);
}
```

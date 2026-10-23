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
    if (unloadingFromGame) return o_WglSwapBuffers(hdc); // флаг, для корректного закрытия dll-файла при отгрузке, чтобы в последние моменты жизни файла, возвращались настоящие данные функции, а не наши подменённые
    static bool imguiInit = false;
  
    if (!imguiInit) { // Срабатывает один раз при подключении dll-файла благодаря static-переменной "imguiInit"!
      gameHwnd = WindowFromDC(hdc); // Получим дескриптор окна-приложения и присвоим в переменную
      ImGui::CreateContext();
      ImGui_ImplWin32_Init(gameHwnd);
      ImGui_ImplOpenGL2_Init();
  
      Gui::Menu::menuManager.UploadTabs();
  
      imguiInit = true;
    }
  
    if (!Settings::configSettings.menuOpen) {
      unloadingFromGame = true;
  
      RequestShutdown();
  
      return o_WglSwapBuffers(hdc);
    }
  
    ImGui_ImplOpenGL2_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();
  
    Gui::Menu::menuManager.DrawMainWindow();
  
    ImGui::Render();
    ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
  
    return o_WglSwapBuffers(hdc);
  }
```

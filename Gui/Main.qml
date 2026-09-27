import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "components"
Window {
    id: mainWindow

    property double windowScale: 0.7
    property int currentActiveTab: 0
    property double procentForRectangle: 0.01

    property color colorForSystemWindow: "transparent"
    property color colorForWindow: "#B34DFF"

    width: Screen.width * windowScale
    height: Screen.height * windowScale

    visible: true
    flags: Qt.Window | Qt.FramelessWindowHint
    color: colorForSystemWindow

    Rectangle {
        anchors.fill: parent
        color: colorForWindow
        radius: parent.height * procentForRectangle

        MenuTabButton {
            id: topCloseButton

            width: mainWindow.height * 0.04
            height: width

            anchors.right: parent.right
            anchors.top: parent.top

            anchors.rightMargin: mainWindow.height * 0.01
            anchors.topMargin: mainWindow.height * 0.01

            onClicked: Qt.quit()
        }

        DragHandler {
            id: windowDragHandler
            onActiveChanged: if (active) mainWindow.startSystemMove()
        }
    }
}

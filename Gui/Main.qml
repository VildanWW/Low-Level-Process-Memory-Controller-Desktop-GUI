import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window
import QWindowKit
import "components"

Window {
    id: mainWindow

    readonly property double windowScale: 0.7
    readonly property double procentForRectangle: 0.01
    readonly property color colorForSystemWindow: "transparent"
    readonly property color colorForWindow: "#3E2352"

    property int currentActiveTab: 0

    minimumWidth: 600
    minimumHeight: 400
    width: Screen.width * windowScale
    height: Screen.height * windowScale
    flags: Qt.Window | Qt.FramelessWindowHint | Qt.WindowMinMaxButtonsHint
    color: colorForSystemWindow
    visible: false

    WindowAgent { id: windowAgent }

    Component.onCompleted: {
        windowAgent.setup(mainWindow)
        windowAgent.setTitleBar(titleBar)
        windowAgent.setHitTestVisible(topCloseButton, true)
        windowAgent.setHitTestVisible(background, false)

        mainWindow.visible = true
    }

    Rectangle {
        id: background
        anchors.fill: parent
        color: colorForWindow
        radius: parent.height * procentForRectangle

        Item {
            id: titleBar
            anchors.top: parent.top
            anchors.left: parent.left
            anchors.right: parent.right
            height: mainWindow.height * 0.06

            MenuTabButton {
                id: topCloseButton
                height: parent.height * 0.6
                width: height
                anchors.right: parent.right
                anchors.verticalCenter: parent.verticalCenter
                anchors.rightMargin: parent.height * 0.2
                onClicked: Qt.quit()
            }
        }
    }
}

import QtQuick
import QtQuick.Controls

Button {
    id: control

    background: Rectangle {
        color: control.hovered ? "#40ffffff" : "transparent"
        radius: parent.height * 0.2
    }

    contentItem: Text {
        text: "✕"
        font.pixelSize: control.height * 0.6
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        color: control.hovered ? "#ffffff" : "#cccccc"
    }
}

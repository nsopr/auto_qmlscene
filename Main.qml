import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Controls.Material 2.15
import QtQuick.Layouts
import QtQuick.Dialogs

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    Material.theme:  Material.Dark
    Material.accent: Material.DeepPurple

    //get font from URL
    // FontLoader {
    //     id: jpFont
    //     source: "https://username.github.io/myapp/fonts/BIZ-UDGothic-01.ttf"
    // }
    FileDialog {
        id: qmlSceneDialog
        title: "qmlsceneを選択してください"
        nameFilters: ["すべてのファイル (*)"]
        onAccepted: {
            qmlscenePATH.text = qmlSceneDialog.currentFile
        }
    }
    FileDialog {
        id: qmlFileDialog
        title: "ファイルを選択してください"
        nameFilters: ["QMLファイル (*.qml)", "すべてのファイル (*)"]
        onAccepted: {
            qmlFilePATH.text = qmlFileDialog.currentFile
        }
    }
    ColumnLayout{
        anchors.centerIn: parent
        width: parent.width * 0.95
        height: parent.height * 0.95
        RowLayout{
            TextField{
                id:qmlscenePATH
                placeholderText: "qmlsceneのPATH"
                Layout.fillWidth: true

            }
            Button{
                text: "参照"
                onClicked: qmlSceneDialog.open()
            }
        }
        RowLayout{
            TextField{
                id:qmlFilePATH
                placeholderText: "監視するQMLファイルのPATH"
                Layout.fillWidth: true
            }
            Button{
                text: "参照"
                onClicked: qmlFileDialog.open()
            }
        }

        Switch {
            id: activator
            objectName: "activator"
            text: checked ? "更新中":"停止中"
            Layout.alignment: Layout.right
            onCheckedChanged: process.checkState(checked, qmlscenePATH.text, qmlFilePATH.text)
        }
    }
}

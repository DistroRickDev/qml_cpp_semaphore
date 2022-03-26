import QtQuick 2.4

Item {
    width: 400
    height: 400

    Rectangle {
        id: outlayer
        x: 100
        y: 0
        width: 200
        height: 400
        color: "#2d2727"

        Rectangle {
            id: rectangle
            x: 8
            y: 8
            width: 184
            height: 384
            color: "#1e1c1c"

            Rectangle {
                id: red
                x: 42
                y: 8
                width: 100
                height: 100
                color: "#ffffff"
                radius: 50
            }

            Rectangle {
                id: yellow
                x: 42
                y: 142
                width: 100
                height: 100
                color: "#ffffff"
                radius: 50
            }

            Rectangle {
                id: green
                x: 42
                y: 276
                width: 100
                height: 100
                color: "#ffffff"
                radius: 50
            }
        }
    }
}

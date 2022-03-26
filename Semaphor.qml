import QtQuick 2.4
import com.example.semaphorecontroller 1.0
Item{
    SemaphoreController{
        id: semaphoreController
    }

    Rectangle {
        anchors.centerIn: parent
        id: outLayer
        x: 100
        y: 0
        width: 200
        height: 400
        color: "#2d2727"

        Rectangle {
            id: innerLayer
            x: 8
            y: 8
            width: 184
            height: 384
            color: "#1e1c1c"

            Rectangle {
                id: redLight
                x: 42
                y: 8
                width: 100
                height: 100
                color: semaphoreController.red
                radius: 50
            }

            Rectangle {
                id: yellowLight
                x: 42
                y: 142
                width: 100
                height: 100
                color: String(semaphoreController.yellow)
                radius: 50
            }

            Rectangle {
                id: greenLight
                x: 42
                y: 276
                width: 100
                height: 100
                color: String(semaphoreController.green)
                radius: 50
            }
        }
    }
}

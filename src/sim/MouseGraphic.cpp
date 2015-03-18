#include "MouseGraphic.h"

#include <Cartesian.h>

#include "GraphicUtilities.h"
#include "Mouse.h"
#include "Param.h"
#include "State.h"

namespace sim{

MouseGraphic::MouseGraphic(const Mouse* mouse) : m_mouse(mouse) {
}

void MouseGraphic::draw() {

    // Only draw the mouse if it's visible and the interface type has been declared
    if (!S()->mouseVisible() || S()->interfaceType() == UNDECLARED) {
        return;
    }

    // First, we draw the wheels
    glColor3fv(COLORS.at(P()->mouseWheelColor()));
    for (Polygon wheelPolygon : m_mouse->getWheelPolygons()) {
        drawPolygon(wheelPolygon);
    }

    // Next, we draw the body
    glColor3fv(COLORS.at(P()->mouseBodyColor()));
    drawPolygon(m_mouse->getBodyPolygon());

    // Only draw the sensors if we're using a discrete interface
    if (S()->interfaceType() == CONTINUOUS) {

        // Next, we draw the sensors
        glColor3fv(COLORS.at(P()->mouseWheelColor()));
        for (Polygon sensorPolygon : m_mouse->getSensorPolygons()) {
            drawPolygon(sensorPolygon);
        }

        // Lastly, we draw the sensor views
        glColor3fv(WHITE);
        for (Polygon polygon : m_mouse->getViewPolygons()) {
            drawPolygon(polygon);
        }
    }
}

} // namespace sim

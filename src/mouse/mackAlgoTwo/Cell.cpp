#include "Cell.h"

namespace mackAlgoTwo {

Cell::Cell() :
        m_position(0),
        m_walls(0),
        m_sequenceNumber(-1),
        m_parent(nullptr),
        m_sourceDirection(-1),
        m_straightAwayLength(0),
        m_distance(-1),
        m_heapIndex(-1) {
}

void Cell::init(
        int x,
        int y,
        int mazeWidth,
        int mazeHeight) {

    // Sanity check
    ASSERT_LE(0, x);
    ASSERT_LE(0, y);
    ASSERT_LT(x, 16);
    ASSERT_LT(y, 16);

    // 0000xxxx << 4 = xxxx0000
    // xxxx0000 | 0000yyyy = xxxxyyyy
    m_position = x << 4 | y;

    // Set the appropriate wall if
    // the cell is on a maze boundary
    if (x == 0) {
        setWall(WEST, true);
    }
    if (y == 0) {
        setWall(SOUTH, true);
    }
    if (x == mazeWidth - 1) {
        setWall(EAST, true);
    }
    if (y == mazeHeight - 1) {
        setWall(NORTH, true);
    }
}

int Cell::getX() const {
    // xxxxyyyy >> 4 = 0000xxxx
    return m_position >> 4;
}

int Cell::getY() const {
    // xxxxyyyy & 00001111 = 0000yyyy
    return m_position & 15;
}

bool Cell::isKnown(int direction) const {
    // Suppose: direction = 2 (south)
    // Then: wsenwsen >> 2 + 4 = 000000ws
    // And: 000000ws & 00000001 = 0000000s
    return (m_walls >> direction + 4) & 1;
}

bool Cell::isWall(int direction) const {
    // Suppose: direction = 2 (south)
    // Then: wsenwsen >> 2 = 00wsenws
    // And: 00wsenws & 00000001 = 0000000s
    return (m_walls >> direction) & 1;
}

void Cell::setWall(int direction, bool isWall) {

    // First, update the wall "known" state
    // Suppose: direction = 2 (south)
    // Then: wsenwsen | 01000000 = w1enwsen
    m_walls |= 1 << direction + 4;

    // Then update the wall value
    if (isWall) {
        // Suppose: direction = 2 (south)
        // Then: wsenwsen | 00000100 = wsenw1en
        m_walls |=  (1 << direction);
    }
    else {
        // Suppose: direction = 2 (south)
        // Then: wsenwsen & 11111011 = wsenw0en
        m_walls &= ~(1 << direction);
    }
}

int Cell::getSequenceNumber() const {
    return m_sequenceNumber;
}

void Cell::setSequenceNumber(int sequenceNumber) {
    m_sequenceNumber = sequenceNumber;
}

Cell* Cell::getParent() const {
    return m_parent;
}

void Cell::setParent(Cell* parent) {
    m_parent = parent;
}

int Cell::getSourceDirection() const {
    return m_sourceDirection;
}

void Cell::setSourceDirection(int sourceDirection) {
    m_sourceDirection = sourceDirection;
}

int Cell::getStraightAwayLength() const {
    return m_straightAwayLength;
}

void Cell::setStraightAwayLength(int straightAwayLength) {
    m_straightAwayLength = straightAwayLength;
}

float Cell::getDistance() const {
    return m_distance;
}

void Cell::setDistance(float distance) {
    m_distance = distance;
}

int Cell::getHeapIndex() const {
    return m_heapIndex;
}

void Cell::setHeapIndex(int index) {
    m_heapIndex = index;
}

} // namespace mackAlgoTwo

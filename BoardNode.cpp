#include "BoardNode.h"
#include "HexMove.h"
#include "NodeStateFactory.h"
#include "NodeState.h"

BoardNode::BoardNode (int x, int y)
  : x_(x)
   ,y_(y)
   ,state(NodeStateFactory::getFactory()->getBlankState())
{
};

HexMove BoardNode::getLocation (void) const {
  HexMove move(x_, y_);

  return move;
}

void BoardNode::colorize (Hex::Color color) {
  if (color == Hex::BLUE) {
    state = NodeStateFactory::getFactory()->getBlueState();
  }
  else if (color == Hex::RED) {
    state = NodeStateFactory::getFactory()->getRedState();
  }
  else {
    state = NodeStateFactory::getFactory()->getBlankState();
  }
}

std::shared_ptr<BoardNode> BoardNode::getUL (void) const {
  return upLeft;
}

std::shared_ptr<BoardNode> BoardNode::getUR (void) const {
  return upRight;
}

std::shared_ptr<BoardNode> BoardNode::getL (void) const {
  return left;
}

std::shared_ptr<BoardNode> BoardNode::getR (void) const {
  return right;
}

std::shared_ptr<BoardNode> BoardNode::getDL (void) const {
  return downLeft;
}

std::shared_ptr<BoardNode> BoardNode::getDR (void) const {
  return downRight;
}

void BoardNode::setUL (std::shared_ptr<BoardNode> node) {
  upLeft = node;
}

void BoardNode::setUR (std::shared_ptr<BoardNode> node) {
  upRight = node;
}

void BoardNode::setL (std::shared_ptr<BoardNode> node) {
  left = node;
}

void BoardNode::setR (std::shared_ptr<BoardNode> node) {
  right = node;
}

void BoardNode::setDL (std::shared_ptr<BoardNode> node) {
  downLeft = node;
}

void BoardNode::setDR (std::shared_ptr<BoardNode> node) {
  downRight = node;
}

void BoardNode::accept (NodeVisitor & v) {
  state->accept(*this, v);
}

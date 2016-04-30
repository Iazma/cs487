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

BoardNode::BoardNode (BoardNode & copy)
  : x_(copy.x_)
    ,y_(copy.y_)
    ,state(copy.state)
{};

BoardNode::~BoardNode (void) { };

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

bool BoardNode::isBlank (void) {
  return state->isBlank();
}

std::shared_ptr<BoardNode> BoardNode::getUL (void) {
  return neighbors["UL"];
}

std::shared_ptr<BoardNode> BoardNode::getUR (void) {
  return neighbors["UR"];
}

std::shared_ptr<BoardNode> BoardNode::getL (void) {
  return neighbors["L"];
}

std::shared_ptr<BoardNode> BoardNode::getR (void) {
  return neighbors["R"];
}

std::shared_ptr<BoardNode> BoardNode::getDL (void) {
  return neighbors["DL"];
}

std::shared_ptr<BoardNode> BoardNode::getDR (void) {
  return neighbors["DR"];
}

std::map<std::string, std::shared_ptr<BoardNode>> & BoardNode::getNeighbors (void) {
  return neighbors;
}

void BoardNode::setUL (std::shared_ptr<BoardNode> node) {
  neighbors["UL"] = node;
}

void BoardNode::setUR (std::shared_ptr<BoardNode> node) {
  neighbors["UR"] = node;
}

void BoardNode::setL (std::shared_ptr<BoardNode> node) {
  neighbors["L"] = node;
}

void BoardNode::setR (std::shared_ptr<BoardNode> node) {
  neighbors["R"] = node;
}

void BoardNode::setDL (std::shared_ptr<BoardNode> node) {
  neighbors["DL"] = node;
}

void BoardNode::setDR (std::shared_ptr<BoardNode> node) {
  neighbors["DR"] = node;
}

void BoardNode::accept (NodeVisitor & v) {
  state->accept(this, v);
}

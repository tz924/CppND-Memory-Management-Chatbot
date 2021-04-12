#include "graphnode.h"
#include "graphedge.h"
#include <iostream>

using namespace std;

GraphNode::GraphNode(int id) { _id = id; }

GraphNode::~GraphNode() {
  //// STUDENT CODE
  ////

  // TASK 0
  // delete _chatBot;

  ////
  //// EOF STUDENT CODE
}

void GraphNode::AddToken(string token) { _answers.push_back(token); }

void GraphNode::AddEdgeToParentNode(GraphEdge *edge) {
  _parentEdges.push_back(edge);
}

// TASK 4
void GraphNode::AddEdgeToChildNode(GraphEdge *edge) {
  // _childEdges.push_back(edge);
  _childEdges.emplace_back(unique_ptr<GraphEdge>(edge));
}

//// STUDENT CODE
////
// TASK 5
// void GraphNode::MoveChatbotHere(ChatBot *chatbot) {
void GraphNode::MoveChatbotHere(ChatBot chatbot) {
  _chatBot = move(chatbot);
  // _chatBot->SetCurrentNode(this);
  _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode) {
  // TASK 5
  // newNode->MoveChatbotHere(_chatBot);
  newNode->MoveChatbotHere(move(_chatBot));
  // _chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index) {
  //// STUDENT CODE
  ////

  // return _childEdges[index];
  // TASK 4
  return _childEdges[index].get();

  ////
  //// EOF STUDENT CODE
}

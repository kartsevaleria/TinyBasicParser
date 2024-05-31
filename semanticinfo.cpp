#include "semanticinfo.h"

//extern VirtualBaseNode* root;

void SemanticInfo::FillInfo(VirtualBaseNode* node)
{
  auto vectorNextNode = node->GetVectorNodes();
  int numLine = 1;
  bool flagNumStr = false;
  for(auto i = vectorNextNode.begin(); i < vectorNextNode.end(); i++ )
  {
      auto currentNode = *i;
      switch (currentNode->GetType())
      {
      case TypeNode::NUM_STATM:
      {
          flagNumStr = true;
          break;
      }
      case TypeNode::STATM:
      {
          numLine++;
          break;
      }
      case TypeNode::GOSUB:
      {
          this->numStringGOSUB.push_back(numLine);
          break;
      }
      default:
          break;
      }
  }
}

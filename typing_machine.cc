// Copyright 2018 <Author>

#include "typing_machine.h"

TypingMachine::TypingMachine() {
  home = cursor = new Node(' ');
  return;
}

void TypingMachine::HomeKey() {
	while (cursor->GetPreviousNode() != nullptr)
	{
		cursor = cursor->MovePre();
	}
	return;
}

void TypingMachine::EndKey() {
	while (cursor->GetNextNode() != nullptr)
	{
		cursor = cursor->MoveNext();
	}
	return;
}

void TypingMachine::LeftKey() {
	if (cursor->GetPreviousNode() != nullptr)
	{
		cursor = cursor->MovePre();
	}
	
	if (cursor->GetPreviousNode() == nullptr)
	{
		home = cursor;
	}

  return;
}

void TypingMachine::RightKey() {
	if (cursor->GetPreviousNode() == nullptr)
	{
		home = cursor->GetNextNode();
	}

	if (cursor->GetNextNode() != nullptr)
	{
		cursor = cursor->MoveNext();
	}

  return;
}

bool TypingMachine::TypeKey(char key) {
	Node *insertNode = cursor->InsertPreviousNode(key);
	if (insertNode->GetPreviousNode() == nullptr)	
  {
		home = insertNode;
	}
	return true;
}

bool TypingMachine::EraseKey() {
	bool result = cursor->ErasePreviousNode();
	if (cursor->GetPreviousNode() == nullptr)	
  {
		home = cursor;
	}
	return result;
}

std::string TypingMachine::Print(char separator) {
  Node *ptr = home;
  std::string str = "";
  if (ptr == nullptr)
  {
    return "";
  }

	while (ptr != nullptr)
	{
		if (cursor == ptr)	
    {
			str += separator;
		}
		else 
    {
			str += ptr->GetData();
		}
		
		ptr = ptr->GetNextNode();
	}
  return str;
}

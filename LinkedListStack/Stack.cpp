#include "Stack.h"

void Stack::Push(int val)
{	
	if(ElementNum == 0)
	{
		FirstElementPtr = new Element(val, nullptr);
		FinalElementPtr = FirstElementPtr;
	}
	else
	{	
		Element* TempFinalElementPtr = FinalElementPtr;
		FinalElementPtr = new Element(val, TempFinalElementPtr);
		TempFinalElementPtr->SetNextElementPtr(FinalElementPtr);
	}
	ElementNum++;
}

int Stack::Pop()
{	
	if (ElementNum == 0)
	{
		return -1;
	}
	int FinalElementValue = FinalElementPtr->GetElementValue();
	if (ElementNum == 1) 
	{	
		delete FirstElementPtr;
		FirstElementPtr = nullptr;
		ElementNum--;
	}
	else
	{
		Element* TempLastElementPtr = FinalElementPtr->GetLastElementPtr();
		delete FinalElementPtr;
		TempLastElementPtr->SetNextElementPtr(nullptr);
		FinalElementPtr = TempLastElementPtr;
		ElementNum--;
	}
	return FinalElementValue;
}

int Stack::Size() const
{	
	/*int ElementCount = 0;
	if (!FirstElementPtr)
	{
		return ElementCount;
	}
	else
	{
		Element* CurrentElementPtr = FirstElementPtr;
		do
		{
			ElementCount++;
			CurrentElementPtr = CurrentElementPtr->GetNextElementPtr();
		} while (CurrentElementPtr);
	}
	return ElementCount;*/
	return ElementNum;
}

bool Stack::Empty() const
{
	return !FirstElementPtr;
}

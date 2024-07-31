#pragma once

class Stack
{
public:
	void Push( int val );
	int Pop();
	int Size() const;
	bool Empty() const;
	Stack() = default;
	Stack(const Stack& StackInput)
	{
		*this = StackInput;
	};

	Stack& operator=(const Stack& StackInput)
	{	
		if (this == &StackInput) {
			return *this;  // 处理自赋值
		}

		// 释放当前资源
		while (FirstElementPtr) {
			Element* temp = FirstElementPtr;
			FirstElementPtr = FirstElementPtr->GetNextElementPtr();
			delete temp;
		}

		Element* InputCurrentElementPtr = StackInput.FirstElementPtr;
		this->FirstElementPtr = new Element(InputCurrentElementPtr->GetElementValue(), nullptr);
		Element* CurrentElementPtr = this->FirstElementPtr;

		while (InputCurrentElementPtr->GetNextElementPtr())
		{	
			InputCurrentElementPtr = InputCurrentElementPtr->GetNextElementPtr();
			CurrentElementPtr = new Element(InputCurrentElementPtr->GetElementValue(), CurrentElementPtr);
		}
		this->FinalElementPtr = CurrentElementPtr;
		this->ElementNum = StackInput.ElementNum;
		return *this;
	};
	~Stack() 
	{
		if(FirstElementPtr)
		{
			Element* LastElementPtr = FinalElementPtr->GetLastElementPtr();
			delete FinalElementPtr;

			while (LastElementPtr)
			{
				FinalElementPtr = LastElementPtr;
				LastElementPtr = LastElementPtr->GetLastElementPtr();
				delete FinalElementPtr;
			}
		}
	}

public:
	class Element 
	{
	public:
		Element(int ValueInput, Element* LastElementPtrInput) :
		Value(ValueInput),
		LastElementPtr(LastElementPtrInput)
		{}

		void SetNextElementPtr( Element* NextElementPtrInput )
		{
			NextElementPtr = NextElementPtrInput;
		}

		int GetElementValue() 
		{
			return Value;
		}

		Element* GetLastElementPtr()
		{
			return LastElementPtr;
		}

		Element* GetNextElementPtr()
		{
			return NextElementPtr;
		}

	private:
		int Value;
		Element* LastElementPtr = nullptr;
		Element* NextElementPtr = nullptr;
	};
private:
	Element* FirstElementPtr = nullptr;
	Element* FinalElementPtr = nullptr;
	int ElementNum = 0;
};
#include "Input.h"
#include "Output.h"
#include <cctype>  //I need it in GETVARIABLE()
#include <sstream>  
#include <iostream> 

Input::Input(window* pW)  
{
	pWind = pW; 
}

void Input::GetPointClicked(Point& P) const  
{
	pWind->WaitMouseClick(P.x, P.y);	
}

string Input::GetString(Output* pO) const  
{
	string Label; 
	char Key;      

	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	
			return "";	
		if (Key == 13)	
			return Label;  
		if ((Key == 8) && (Label.size() >= 1))	
			Label.resize(Label.size() - 1);	
		else
			Label += Key; 

		if (pO)
			pO->PrintMessage(Label); 
	}
}
// بدايه التو دو
double Input::GetValue(Output* pO) const	// Reads a double value from the user أنا عاملها
{
	double D = 0;  // لتخزين القيمة المدخلة

	if (pO) pO->PrintMessage("Please enter a numeric value"); // توجيه المستخدم

	while (true)
	{
		string input = GetString(pO); // قراءة النص
		if (input.empty()) continue;

		stringstream ss(input);
		if (ss >> D) 
		{
			char c;
			if (!(ss >> c)) break; 
		}
		if (pO) pO->PrintMessage("Invalid input! Enter a numeric value:"); // خطأ في الإدخال
	}
	
	return D; 
}


string Input::GetVariable(Output* pO) const  // Get a valid variable name أنا عاملها
{
	if (pO) pO->PrintMessage("Enter variable name:"); // توجيه المستخدم
	string var;

	while (true)
	{
		var = GetString(pO); 
		if (var.empty()) continue;

		bool valid = isalpha(var[0]); 
		for (size_t i = 0; i < var.size(); i++) {
			char c = var[i];
			if (!isalnum(c) && c != '_') valid = false;
		}
		if (valid) break;  // بخلص التشيك
		if (pO) pO->PrintMessage("Invalid variable name. Try again:"); // رسالة خطأ
	}

	return var; // برجع الفاريبل
}
// to read a “variable name” from the user (from the keyboard). 
// It does not return before taking a valid variable name.

char Input::GetArithOperator(Output* pO) const  // Get arithmetic operator أنا عاملها
{
	if (pO) pO->PrintMessage("Enter arithmetic operator (+, -, *, /):"); // اليوزر بيختار عمليه
	char op;

	while (true)
	{
		string s = GetString(pO);
		if (s.size() == 1 && (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/'))
		{
			op = s[0]; // تم إدخال عامل صحيح
			break;
		}
		if (pO) pO->PrintMessage("Invalid operator. Try again:"); // ايرور لليوزر
	}

	return op; // إرجاع العامل
}

string Input::GetCompOperator(Output* pO) const  // Get comparison operator أنا عاملها
{
	if (pO) pO->PrintMessage("Enter comparison operator (==, !=, <, <=, >, >=):"); // توجيه المستخدم
	string op;

	while (true) //  مهمه دي اتطلبت بالنص
	{
		op = GetString(pO);
		if (op == "==" || op == "!=" || op == "<" || op == "<=" || op == ">" || op == ">=")
			break; // تم إدخال عامل مقارنة صحيح
		if (pO) pO->PrintMessage("Invalid comparison operator. Try again:"); // ايرور لليوزر
	}

	return op; 
}

ActionType Input::GetUserAction() const// I did NOT get it without help (HARD)
{
	int x, y; // إحداثيات الكليك
	pWind->WaitMouseClick(x, y);	// هنا مستني الماوس يكلك عند احداثيات معينه

	if (UI.AppMode == DESIGN)	// طول ما لسه بنعمل ديزين
	{
		
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItem = (x / UI.MenuItemWidth); // تحديد أي أيقونة تم الضغط عليها
			switch (ClickedItem)
			{
			case ITM_VALUE_ASSIGN: return ADD_VALUE_ASSIGN; 
			case ITM_COND: return ADD_CONDITION;          
			case ITM_EXIT: return EXIT;                   
			default: return DSN_TOOL;     //السوتش كيسس كانت موجوده
			}
		}

		
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
			return (x <= UI.DrawingAreaWidth) ? DRAWING_AREA : OUTPUT_AREA; // منطقة الرسم أو المخرجات

		
		return STATUS; 
	}
	else	
	{
		return SWITCH_DSN_MODE;	
	}
}

Input::~Input()  // Destructor مفيهاش محتوي
{
}


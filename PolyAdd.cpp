/************************************************************************************************************/
/*****************************给定两个一元多项式，实现两个一元多项式的相加算法。******************************/
/************************************************************************************************************/


#include<iostream>
#include<queue>
using namespace std;

// 一元多项式节点
// 由于实验1已经使用过链表的形式进行数组处理，这里我选择队列进行数据处理
struct MulaData
{
	double num_1;
	int num_2;
};

// 相关方法
class PolyAdd {
public:
	queue<MulaData> setFormula();// 建立一元多项式
	void showFormula(queue<MulaData> formula);// 输出一元多项式
	queue<MulaData> addFormula(queue<MulaData> formulaOne, queue<MulaData> formulaTwo);// 一元多项式相加
};

// 建立一元多项式
queue<MulaData> PolyAdd::setFormula()
{
	queue<MulaData> formula;
	MulaData Num_Get;
	std::cin >> Num_Get.num_1;
	while (Num_Get.num_1 != -1)
	{
		std::cin >> Num_Get.num_2;
		formula.push(Num_Get);
		std::cin >> Num_Get.num_1;
	}
	cout << "创建结束" << endl;
	return formula;
}

// 输出一元多项式
void PolyAdd::showFormula(queue<MulaData> formula)
{
	MulaData showNum;
	while (!formula.empty())
	{
		showNum = formula.front();
		formula.pop();
		cout << showNum.num_1 << "x^" << showNum.num_2;
		if (!formula.empty()) cout << '+';
	}
	cout << '\n';
}

// 一元多项式相加
queue<MulaData> PolyAdd::addFormula(queue<MulaData> formulaOne, queue<MulaData> formulaTwo)
{
	MulaData Save_1, Save_2;
	queue<MulaData> result_Res;
	// 当两者不为空
	while ((!formulaOne.empty()) && (!formulaTwo.empty())) {
		Save_1 = formulaOne.front(); 
		Save_2 = formulaTwo.front();
		if (Save_1.num_2 == Save_2.num_2) {
			Save_1.num_1 += Save_2.num_2;
			result_Res.push(Save_1);
			formulaOne.pop();
			formulaTwo.pop();
		}
		else if (Save_1.num_2 >= Save_2.num_2) {
			result_Res.push(Save_1);
			formulaOne.pop();
		}
		else {
			result_Res.push(Save_2);
			formulaTwo.pop();
		}
	}
	// 其中之一为空
	if (formulaOne.empty()) {
		while (!formulaTwo.empty()) {
			result_Res.push(formulaTwo.front());
			formulaTwo.pop();
		}
	}
	else {
		while (!formulaOne.empty()) {
			result_Res.push(formulaOne.front());
			formulaOne.pop();
		}
	}
	return result_Res;
}





// 测试函数
//int main() {
//	queue<MulaData> formula_1;
//	queue<MulaData> formula_2;
//	queue<MulaData> resultFor;
//	PolyAdd RunWay;
//	cout << "建立第一个一元多项式，输入-1停止建立:\n" << endl;
//	formula_1 = RunWay.setFormula();
//	cout << "建立第二个一元多项式，输入-1停止建立:\n" << endl;
//	formula_2 = RunWay.setFormula();
//	cout << "建立结果为:\n" << endl;
//	RunWay.showFormula(formula_1);
//	RunWay.showFormula(formula_2);
//	cout << "相加结果为:\n" << endl;
//	resultFor = RunWay.addFormula(formula_1, formula_2);
//	RunWay.showFormula(resultFor);
//	return 0;
//}


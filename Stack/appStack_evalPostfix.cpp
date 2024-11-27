#include <iostream>
using namespace std;

int isEmpty(int top)
{
    return top == -1;
}

int isFull(int top)
{
    return top == 4;
}

void push(int val, int &top, int arr[])
{
    if (isFull(top))
    {
        cout << "Can't push, arr is full." << endl;
    }
    else
    {
        top++;
        arr[top] = val;

        cout << "Done add " << arr[top] << endl;
    }
}

int pop(int &top, int arr[]) 
{
    if (isEmpty(top))
    {
        cout << "Can't pop, Stack is empty!" << endl;
		return 0;
    }
    else
    {
        cout << "Done remove " << arr[top] << endl;

		int val;
        val = arr[top];

        arr[top] = 0;
        top--;

		return val;
    }
}

int calc(int op , int val1 , int val2)
{
	int ans;

	switch (op) {
	case '+':
		ans = val1 + val2;
		cout << val1 << " + " << val2 << " = " << ans << endl;
		break;
	case '-':
		ans = val1 - val2;
		cout << val1 << " - " << val2 << " = " << ans << endl;
		break;
	case '*':
		ans = val1 * val2;
		cout << val1 << " * " << val2 << " = " << ans << endl;
		break;
	case '/':
		ans = val1 / val2;
		cout << val1 << " / " << val2 << " = " << ans << endl;
		break;
	}
	return ans;
}

int evalPostfix(const string & ex , int top , int arr[])
{
	for(int i = 0; i < ex.length(); i++)
	{
		char ch = ex[i];
		if (ch == ' ')
			continue;
		else if (isdigit(ch))
		{
			push(ch-'0', top , arr);
		}
		else if (ch == '*' || ch == '/' || ch == '+' || ch == '-')
		{
			int val1 = pop(top , arr);
			int val2 = pop(top , arr);

			int result = calc(ch , val1 , val2);

			push(result, top , arr);
		}
		
	}
	return pop(top , arr);
}


int main()
{

    int top = -1;
    int arr[] = {0};

	string exp = "6 5 3 2 + 8 * + 3 + *";

	int res = evalPostfix(exp, top , arr);

    cout << "The result of [ " << exp << " ] is " << res;
}

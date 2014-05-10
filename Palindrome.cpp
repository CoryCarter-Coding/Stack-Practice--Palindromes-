#include <iostream>   
#include <stack>   

using namespace std;   

int main ()
{
	std::stack<char> backward_stack; //original input stored backward
	std::stack<char> forward_stack; //pop-pushed in order to be read forward
	std::stack<char> matching_stack; //for matching/palindrome verification
	
	string input; //for matching purposes.
	int mismatches; //counts mismatches/flag for non-palindrome.
	
	cout << "Enter a word or phrase: ";
	getline(cin, input);
	
	for(int i = 0; i < input.length(); i++) // reading in....
	{
		if(isalpha(input[i]))
		{
			backward_stack.push(toupper(input[i]));
			matching_stack.push(toupper(input[i]));
		}
	}
	
	while(!backward_stack.empty()) //reads forward...
	{
			forward_stack.push(backward_stack.top());
			backward_stack.pop();
	}
		
	while(!matching_stack.empty()) //attempts to match
	{
		if(matching_stack.top() == forward_stack.top())
		{
			matching_stack.pop();
			forward_stack.pop();
		}
		else
		{
			mismatches++;
			
			matching_stack.pop();
			forward_stack.pop();
		}
	}	
	
	if(mismatches == 0) //prints....
	{
		cout << input << " is a palindrome." << endl;
	}
	else
	{
		cout << input << " is not a palindrome." << endl;
	}

  	return 0;
}
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int size = tokens.size();
        stack <long long> numbers; 
        //ascii for operators are below 48
        long long a, b, temp;
        for (int i = 0; i < size ; i++){
            //basically just number, so just push to stack
            temp = static_cast<int>(tokens[i][0]);
            if (tokens[i].size() > 1 || temp >= 48){
                numbers.push(stoi(tokens[i]));
            }
            else{
                a = numbers.top();
                numbers.pop();
                b = numbers.top();
                numbers.pop();
                if(tokens[i] == "+"){
                    numbers.push(b+a);
                }
                else if(tokens[i] == "-"){
                    numbers.push(b-a);
                }
                else if(tokens[i] == "/"){
                    numbers.push(b/a);
                }
                else if(tokens[i] == "*"){
                    numbers.push(b*a);
                }
                
            }
                
            
        }
        return numbers.top();
    }
};
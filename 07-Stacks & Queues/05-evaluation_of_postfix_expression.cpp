int evaluatePostfix(string S){
        stack<int> s;
        for (auto i : S){
            if (i>='0')
                s.push(i-'0');
            else{
                int b = s.top();s.pop();
                int a = s.top();s.pop();
                switch(i){
                    case '*':
                        s.push(a*b);
                        break;
                    case '+':
                        s.push(a+b);
                        break;
                    case '-':
                        s.push(a-b);
                        break;
                    case '/':
                        s.push(a/b);
                        break;
                }
            }
        }
        return s.top();
    }
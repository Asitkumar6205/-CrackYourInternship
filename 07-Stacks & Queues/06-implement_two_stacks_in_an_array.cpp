void twoStacks :: push1(int x){
    arr[++top1] = x;
}
void twoStacks ::push2(int x){
    arr[--top2] = x;
}
int twoStacks ::pop1(){
    return top1 == -1 ? -1 : arr[top1--];
}
int twoStacks :: pop2(){
    return top2 == size ? -1 : arr[top2++];
}
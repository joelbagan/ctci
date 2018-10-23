#include <string>

int main(){
    for(int i = 0; i <= 100; i++){
        string out = "";
        out += i % 3 == 0 ? "fizz" : "";
        out += i % 5 == 0 ? "buzz" : "";
        if(out == ""){
            printf("%i\n", i);
        }
        else{
            printf("%s\n", out);
        }
    }
}
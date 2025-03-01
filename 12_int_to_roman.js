//https://leetcode.com/problems/integer-to-roman/
//12. Integer to Roman
/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function(num) {
    let s="";
    if(num>=1000)
        {   s=s+('M').repeat(num/1000);
            num=num%1000;
            if (num===0){
                return s;
            }
        }
        
        if(num>=900)
        {
            s=s+'CM';
            num-=900;
            if (num===0){
                return s;
            }
        }
        else{
            s=s+('D').repeat(num/500);
            num=num%500;
            if (num===0){
                return s;
            }
        }

        if(num>=400)
        {   s=s+'CD';
            num-=400;
            if (num===0){
                return s;
            }
        }
        else{
            s=s+('C').repeat(num/100);
            num=num%100;
            if (num===0){
                return s;
            }
        }

        if(num>=90)
        {
            s=s+'XC';
            num-=90;
            if (num===0){
                return s;
            }
        }
        else{
            s=s+('L').repeat(num/50);
            num=num%50;
            if (num===0){
                return s;
            }
        }

        if(num>=40)
        {   s=s+'XL';
            num-=40;
            if (num===0){
                return s;
            }
        }
        else{
            s=s+('X').repeat(num/10);
            num=num%10;
            if (num===0){
                return s;
            }
        }

        if(num>=9)
        {
            s=s+'IX';
            return s;
        }
        else if(num===4)
        {
            s=s+'IV';
            return s;
        }
        else{
            s=s+('V').repeat(num/5);
            num=num%5;
            s=s+('I').repeat(num);
        }
        return s;

    };
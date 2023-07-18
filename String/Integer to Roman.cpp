class Solution {
public:
    string intToRoman(int num) {
        string ans="";
        int m=num/1000;
        num%=1000;
        while(m--)
        ans+='M';
        if(num>=900)
        {
            ans+="CM";
            num%=900;
        }
        else if(num>=500)
        {
            num%=500;
            ans+='D';
        }
        if(num>=400)
        {
            ans+="CD";
            num%=400;
        }
        else if(num>=100)
        {
            int c=num/100;
            num%=100;
            while(c--)
            ans+='C';
        }
        if(num>=90)
        {
            ans+="XC";
            num%=90;
        }
        else if(num>=50)
        {
            num%=50;
            ans+='L';
        }
        if(num>=40)
        {
            ans+="XL";
            num%=40;
        }
        else if(num>=10)
        {
            int c=num/10;
            num%=10;
            while(c--)
            ans+='X';
        }
        if(num>=9)
        {
            ans+="IX";
            num%=9;
        }
        else if(num>=5)
        {
            num%=5;
            ans+='V';
        }
        if(num>=4)
        {
            ans+="IV";
            num%=4;
        }
        while(num--)
        ans+='I';
        return ans;
    }
};
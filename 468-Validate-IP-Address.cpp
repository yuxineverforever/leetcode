/**
 * Check a valid IP address.
 *
 *
 */
class Solution {
public:
//2021.9.29
//IPV4不合法情况 1.前导0  2.数大于255  3.分隔符间多余三个数  4.超长  5.超短 6.分隔符挨着 7.分隔符过多
//IPV6不合法情况 1.分隔符间多于四个数  2.超长  3.超短 4.分隔符挨着 5.分隔符过多 6.不在16进制范围
    string validIPAddress(string IP)
    {
        if(isIPV4(IP))
            return "IPv4";
        if(isIPV6(IP))
            return "IPv6";
        return "Neither";
    }
    bool isIPV4(string IP)
    {
        vector<string>res;
        split(IP,res,'.',3);
        if(res.size() != 4)//段数超长或超短
            return false;
        for(int i=0;i<res.size();i++)
        {
            string temp = res[i];
            if(temp[0] == '0' && temp.size() > 1)//前导0
                return false;
            if(temp.size() > 3)//段内超长
                return false;
            int num = 0;
            for(int j=0;j<temp.size();j++)//获取数的同时检查是否只由数字构成
            {
                num = 10*num + temp[j]-'0';
                if(temp[j] < '0' || temp[j] > '9')
                    return false;
            }
            if(num > 255)//超大
                return false;
        }
        return true;
    }
    bool isIPV6(string IP)
    {
        vector<string>res;
        split(IP,res,':',7);
        if(res.size() != 8)//段数超长或超短
            return false;
        for(int i=0;i<res.size();i++)
        {
            string temp = res[i];
            if(temp.size() > 4)//段内超长
                return false;
            for(int j=0;j<temp.size();j++)//检查是否只由数字、大小写构成
            {
                if((temp[j]>='0' && temp[j]<='9') || (temp[j]>='a' && temp[j]<='f') || (temp[j]>='A' && temp[j]<='F'))//注意16进制
                    continue;
                else
                    return false;
            }
        }
        return true;
    }
    void split(string s,vector<string>&res,char delimiter,int delimitercnt)//以delimiter将s划分
    {
        int i = 0;
        int cnt = 0;
        string temp;
        while(i <s.size())
        {
            if(s[i] != delimiter)//不为分隔符加入
                temp.push_back(s[i]);
            if(s[i] == delimiter || i==s.size()-1)//为分隔符或者最后一个字段
            {
                if(temp.size() == 0)//temp为空说明刚清空了temp, 即两个分隔符连一起的情况
                {
                    res.clear();
                    return;
                }
                if(s[i] == delimiter)//计算分隔符数
                    cnt++;
                if(cnt > delimitercnt)//分隔符数量多于限制
                {
                    res.clear();
                    return;
                }
                res.push_back(temp);
                temp.clear();
            }
            i++;
        }
    }
};
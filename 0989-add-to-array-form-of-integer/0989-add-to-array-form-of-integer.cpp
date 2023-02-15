class Solution
{
    public:
        vector<int> addToArrayForm(vector<int> &v, int k)
        {
            int n = v.size();
           	// int carry=k%10;
            reverse(v.begin(), v.end());
            vector<int> vv;
            while (k > 0)
            {
                vv.push_back(k % 10);
                k /= 10;
            }
            int m = vv.size();
            int carry = 0;
            int a = 0;
            int i = 0;
            while (i < m || i < n)
            {
                if (i < m && i < n)
                {
                    if (i + 1 == n && i + 1 == m)
                    {
                        a = v[i] + vv[i] + carry;
                        if (a >= 10)
                        {
                            v[i] = a % 10;
                            vv[i] = a % 10;
                            carry = a / 10;
                            v.push_back(carry);
                            vv.push_back(carry);
                        }
                        else
                        {
                            v[i] = a;
                            vv[i] = a;
                            carry = 0;
                        }
                    }
                    else
                    {
                        a = v[i] + vv[i] + carry;
                        if (a >= 10)
                        {
                            v[i] = a % 10;
                            vv[i] = a % 10;
                            carry = a / 10;
                        }
                        else
                        {
                            v[i] = a;
                            vv[i] = a;
                            carry = 0;
                        }
                    }
                }
                else
                {
                    if (i < n)
                    {
                        if (i + 1 == n)
                        {
                            a = v[i] + carry;
                            if (a >= 10)
                            {
                                v[i] = a % 10;

                                carry = a / 10;
                                v.push_back(carry);
                                carry = 0;
                            }
                            else
                            {
                                v[i] = a;
                                carry = 0;
                            }
                        }
                        else
                        {
                            a = v[i] + carry;
                            if (a >= 10)
                            {
                                v[i] = a % 10;
                                carry = a / 10;
                            }
                            else
                            {
                                v[i] = a;
                                carry = 0;
                            }
                        }
                    }
                        if (i < m)
                        {

                            if (i + 1 == m)
                            {
                                a = vv[i] + carry;
                                if (a >= 10)
                                {

                                    vv[i] = a % 10;
                                    carry = a / 10;
                                    vv.push_back(carry);
                                    carry = 0;
                                }
                                else
                                {

                                    vv[i] = a;
                                    carry = 0;
                                }
                            }
                            else
                            {
                                a = vv[i] + carry;
                                if (a >= 10)
                                {
                                    vv[i] = a % 10;
                                    carry = a / 10;
                                }
                                else
                                {
                                    vv[i] = a;
                                    carry = 0;
                                }
                            }
                        }
                    }
                    i += 1;
                }
                reverse(v.begin(), v.end());
                reverse(vv.begin(), vv.end());
                if (n > m)
                    return v;
                else return vv;
            }
        };
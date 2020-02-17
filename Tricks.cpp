//Reverse array sorting
sort(arr, arr+n, greater<int>());

//*String to Decimal
atoi(str.c_str());

//*Decimal to String
int a = 10;
stringstream ss;
ss << a;
string str = ss.str();

//*Decimal to Binary
string result = bitset<32>(number).to_string();
cout << result.substr(result.find("1", 0));

Strings Tricks//

size_t found = str.find(str1);
if (found != string::npos) { }
transform(data.begin(), data.end(), data.begin(), ::tolower);


//*Count set bits in an integer
__builtin_popcount();

//**GCD (__gcd(a, b))
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

//*LCM
ll findlcm(int arr[], int n)
{
    // Initialize result
    ll ans = arr[0];

    for (int i = 1; i < n; i++)
        ans = (((arr[i] * ans)) /
                (gcd(arr[i], ans)));

    return ans;
}

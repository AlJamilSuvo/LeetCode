#include "list_node_util.hpp"

using namespace std;

class Solution
{
public:
    int pairSum(ListNode *head)
    {
        map<int, int> to_array;
        int list_size = 0;
        while (head != nullptr)
        {
            to_array[list_size] = head->val;
            list_size += 1;
            head = head->next;
        }
        int max_sum = -2147483648;
        for (int i = 0; i < list_size / 2; i++)
        {
            int sum = to_array[i] + to_array[list_size - i - 1];
            if (sum > max_sum)
                max_sum = sum;
        }

        return max_sum;
    }
};

int main()
{
    vector<int> l1 = {5, 4, 2, 1};
    vector<int> l2 = {4, 2, 2, 3};
    vector<int> l3 = {1, 100000};
    ListNode *h1 = create_list_node(l1);
    ListNode *h2 = create_list_node(l2);
    ListNode *h3 = create_list_node(l3);

    Solution s;
    cout << s.pairSum(h1) << endl;
    cout << s.pairSum(h2) << endl;
    cout << s.pairSum(h3) << endl;
}
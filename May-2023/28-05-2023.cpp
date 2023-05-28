// C++ Solution
class Solution{
public:
    int getNthFromLast(Node *head, int n) {
  int cnt = 0;
  Node *n1 = head;
  while (n1 != NULL) {
    n1 = n1->next;
    cnt++;
  }

  if (cnt < n) {
    // Invalid value of n
    return -1;
  }

  int i = 1;
  int target = cnt - n + 1;
  while (i < target) {
    head = head->next;
    i++;
  }

  return head->data;
}
};

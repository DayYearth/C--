/*Chuyển phát hàng là một công việc quan trọng trong thương mại điện tử là lĩnh vực phát triển bùng nổ trong thời gian hiện nay.
Ta xét công việc của một nhân viên giao hàng của Công ty XYZ chuyên bán hàng trên mạng.
Nhân viên giao hàng cần phát các kiện hàng (được đóng gói trong các hộp cùng kích thước) đến các khách hàng có địa chỉ trên một đại lộ có dạng một đường thẳng.

Nhân viên giao hàng sẽ nhận các kiện hàng tại trụ sở công ty ở vị trí x=0, và cần chuyển phát hàng đến n khách hàng, được đánh số từ 1đến n
Biết xi và mi là vị trí của khách hàng i và số lượng kiện hàng cần chuyển cho khách hàng này.
Do các kiện hàng là khá cồng kềnh nên mỗi lần đi chuyển phát nhân viên giao hàng chỉ có thể mang theo không quá k kiện hàng.

Nhân viên giao hàng xuất phát từ trụ sở, nhận một số (không quá k) kiện hàng và di chuyển theo đại lộ để chuyển phát cho một số khách hàng.
Khi giao hết các kiện hàng mang theo, nhân viên giao hàng lại quay trở về trụ sở và lặp lại công việc nói trên cho đến khi chuyển phát được tất cả các kiện hàng cho khách hàng.
Sau khi kết thúc công việc chuyển phát, nhân viên phải quay trở lại trụ sở công ty để nộp cho phòng kế toán tất cả các hóa đơn giao nhận có ký nhận của khách hàng.
Giả thiết là: tốc độ di chuyển của nhân viên là 1 đơn vị khoảng cách trên một đơn vị thời gian.
Thời gian nhận hàng ở trụ sở công ty và thời gian bàn giao hàng cho khách hàng được coi là bằng 0.

Yêu cầu: Giả sử thời điểm mà nhân viên giao hàng bắt đầu công việc là 0. Hãy giúp nhân viên giao hàng tìm cách hoàn thành công việc đã mô tả ở trên tại thời điểm sớm nhất.

Input
Dòng đầu tiên chứa hai số nguyên dương được ghi cách nhau bởi dấu cách n và k
 (n≤1000;k≤10^7)

Dòng thứ i trong số n dòng tiếp theo chứa hai số nguyên được ghi cách nhau bởi dấu cách xi(|xi|≤10^7) và mi(1≤mi≤10^7)
Output
Ghi ra một số nguyên là thời điểm sớm nhất mà người giao hàng có thể hoàn thành nhiệm vụ của mình.

Example:
Input
7 1
9400000 10000000
9500000 10000000
9600000 10000000
9700000 10000000
9800000 10000000
9900000 10000000
10000000 10000000
output
1358000000000000

Input
4 10
-7 5
-2 3
5 7
9 5
Output
42 */
#include <bits/stdc++.h>

using namespace std;

struct Customer {
  int x;
  int m;
};

int n, k;
vector<Customer> customers;

int dp[100][100];

int solve(int cur_customers, int cur_items) {
  if (cur_customers == n) {
    // Đã giao hàng cho tất cả các khách hàng
    return 0;
  }

  if (dp[cur_customers][cur_items] != -1) {
    // Đã tính toán rồi
    return dp[cur_customers][cur_items];
  }

  // Thời gian để giao hàng cho các khách hàng hiện tại
  int time = 0;
  for (int i = 0; i < cur_customers; i++) {
    time += abs(customers[i].x);
  }

  // Thời gian để quay trở về trụ sở
  time += abs(customers[cur_customers].x);

  // Thời gian để giao hàng cho các khách hàng tiếp theo
  int min_time = INT_MAX;
  for (int i = cur_items; i <= k; i++) {
    int next_customers = cur_customers + i;
    int next_items = cur_items - i;
    min_time = min(min_time, solve(next_customers, next_items) + time);
  }

  dp[cur_customers][cur_items] = min_time;
  return min_time;
}

int main() {
  cin >> n >> k;
  customers.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> customers[i].x >> customers[i].m;
  }

  // Khởi tạo bảng DP
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      dp[i][j] = -1;
    }
  }

  // Tính toán thời gian cần thiết để hoàn thành công việc
  int time = solve(0, k);

  // In ra kết quả
  cout << time << endl;
  return 0;
}

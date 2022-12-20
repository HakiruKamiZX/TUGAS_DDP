#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
  int T;
  cin >> T;

  for (int t = 1; t <= T; t++)
  {
    int N;
    cin >> N;

    vector<int> w(N), l(N);
    for (int i = 0; i < N; i++)
    {
      cin >> w[i] >> l[i];
    }

    vector<double> rpi(N);
    for (int i = 0; i < N; i++)
    {
      double win_pct = (double)w[i] / (w[i] + l[i]);
      double opp_win_pct = 0.0;
      for (int j = 0; j < N; j++)
      {
        if (i == j)
          continue;
        opp_win_pct += (double)w[j] / (w[j] + l[j]);
      }
      opp_win_pct /= (N - 1);
      rpi[i] = 0.25 * win_pct + 0.50 * opp_win_pct;
      if (w[i] + l[i] > 0)
        rpi[i] += 0.25 * (double)(w[i]) / (w[i] + l[i]);
    }

    cout << "Case #" << t << ":";
    for (int i = 0; i < N; i++)
    {
      cout << " " << rpi[i];
    }
    cout << endl;
  }

  return 0;
}
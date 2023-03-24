#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

using vi = vector<int>;

class solution {
public:
	solution() = default;

	virtual ~solution() = default;

private:
	int n_{};
	vi p_{};
	int ans_{};

public:
	void input() {
		cin >> n_;

		p_ = vi(n_);
		for (auto i = 0; i < n_; ++i) {
			cin >> p_[i];
		}
	}

	void solve() {
		if (1 == n_) {
			ans_ = p_[0];
			return;
		}

		if (2 == n_) {
			ans_ = p_[0] + p_[1];
			return;
		}

		auto dp_ = vi(n_, -1);
		dp_[0] = p_[0];
		dp_[1] = p_[0] + p_[1];

		for (auto i = 2; i < n_; ++i) {
			if (2 == i) {
				const auto& s1 = p_[0] + p_[1];
				const auto& s2 = p_[0] + p_[2];
				const auto& s3 = p_[1] + p_[2];
				dp_[i] = max({ s1, s2, s3 });
				continue;
			}

			const auto& s1 = dp_[i - 3] + p_[i - 1] + p_[i];
			const auto& s2 = dp_[i - 2] + p_[i];
			const auto& s3 = dp_[i - 1];
			dp_[i] = max({ s1, s2, s3 });
		}

		ans_ = dp_[n_ - 1];
	}

	void output() const noexcept {
		cout << ans_;
	}
};

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	auto s = solution{};
	s.input();
	s.solve();
	s.output();

	return 0;
}
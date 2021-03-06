/* Authors : Frejoux G. & Niord M. */

#pragma once

#include "resources.h"
#include "utils.h"
#include "dice.h"

namespace coo_yahtzee {

	class roll {

	public:

		roll(const std::vector<dice*>& dices);
		roll(const roll&) = default;
		~roll();

	private:

		std::vector<dice*> dices_;
		int round_count_;

		// Sort dices
		void sort_dices() {
			std::sort(dices_.begin(), dices_.end(), dice::compare_dice_pointers);
		}

		// Roll all dices
		void roll_dices();

		// Roll one or several dices by their positions
		void roll_dice(const std::vector<int>& positions);

		// Get the count of a value among dices
		int get_number_of(const int& value) const;

		// Friends
		friend std::ostream& operator<<(std::ostream& out, const roll&);
		friend class player;
		friend class ai_player;

		// Tests
		friend class Test_Roll;
		friend class Test_Player;

	};

	std::ostream& operator<<(std::ostream& out, const roll&);

}


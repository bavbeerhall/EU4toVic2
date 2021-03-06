#ifndef EU4_ARMY_H
#define EU4_ARMY_H

#include <vector>
#include "EU4Regiment.h"
#include "../../Mappers/UnitTypes/UnitTypeMapper.h"

namespace EU4
{
	class EU4Army : public commonItems::parser
	{
	public:
		EU4Army() = default;
		EU4Army(std::istream& theStream, const std::string& potentialNavy); // Also applies to ships
		[[nodiscard]] const auto& getName() const { return name; }
		[[nodiscard]] auto getLocation() const { return location; }
		[[nodiscard]] auto getArmyFloats() const { return armyFloats; }
		[[nodiscard]] const auto& getRegiments() const { return regimentList; }
		
		[[nodiscard]] double getAverageStrength(REGIMENTCATEGORY category) const;
		[[nodiscard]] int getTotalTypeStrength(REGIMENTCATEGORY category) const;

		void resolveRegimentTypes(const mappers::UnitTypeMapper& unitTypeMapper);

	private:
		std::string name;
		int location = 0;
		bool armyFloats = false;
		std::vector<EU4Regiment> regimentList;
	};
}
#endif // EU4_ARMY_H

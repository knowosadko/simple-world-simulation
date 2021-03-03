#include "Zwierze.h"
#include "Swiat.h"
class Owca : public Zwierze {
public:
	Owca(Swiat& swiat);
	Owca(int Id, int sila, int inicjatywa, std::string gatunek, Swiat& swiat, int x, int y);
	WynikKolizji walka(int ID) override;
	void rozmnazanie() override;
	void rysowanie();
};
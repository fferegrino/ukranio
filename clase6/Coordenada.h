class Coordenada
{
	private:
		double x;
		double y;
		double distanciaOrigen;
	public:
		Coordenada(double = 0, double = 0);
		double X();
		double Y();
		double D();
		bool operator <(const Coordenada& other) const;
};

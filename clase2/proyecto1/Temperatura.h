#ifndef __TEMPERATURA_H__
#define __TEMPERATURA_H__
class Temperatura
{
	private:
		 double kelvin;
		 double farenheit;
		 double celsius;
	public:
		Temperatura(double kelvin);
		void setTempKelvin(double kelvin);
		void setTempFarenheit(double farenheit);
		void setTempCelsius(double celsius);
		double getCelsius();
		double getFarenheit();
		double getKelvin();
		void imprimeK();
		void imprimeC();
		void imprimeF();
		
};
#endif

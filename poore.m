% pöördemaatriksi ehitamisega euleri nurkade a,b,g jaoks

function [R]=poore(a,b,g)

pir=pi/180;

ag=a*pir;
bg=b*pir;
gg=g*pir;

	Rg11=cos(ag)*cos(bg)*cos(gg)-sin(ag)*sin(gg);
	Rg12=sin(ag)*cos(bg)*cos(gg)+cos(ag)*sin(gg);
	Rg13=-sin(bg)*cos(gg);
   Rg21=-cos(ag)*cos(bg)*sin(gg)-sin(ag)*cos(gg);
   Rg22=-sin(ag)*cos(bg)*sin(gg)+cos(ag)*cos(gg);
   Rg23=sin(bg)*sin(gg);
   Rg31=cos(ag)*sin(bg);
   Rg32=sin(ag)*sin(bg);
   Rg33=cos(bg);
   R=[Rg11 Rg12 Rg13
      Rg21 Rg22 Rg23
      Rg31 Rg32 Rg33];
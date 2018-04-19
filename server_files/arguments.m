%#!/usr/bin/octave -qf

arg_list = argv ();
as = str2num(arg_list{1});
ae = str2num(arg_list{2});
bs = str2num(arg_list{3});
be = str2num(arg_list{4});
gs = str2num(arg_list{5});
ge = str2num(arg_list{6});

gonio12_optimum(as, ae, bs, be, gs, ge)

%#!/usr/bin/octave -qf

arg_list = argv ();
rot= str2num(arg_list{1});
as = str2num(arg_list{2});
ae = str2num(arg_list{3});
bs = str2num(arg_list{4});
be = str2num(arg_list{5});
gs = str2num(arg_list{6});
ge = str2num(arg_list{7});
if rot == 1
    rot = 'a';
elseif rot == 2
    rot = 'b';
elseif rot == 3
    rot = 'c';
elseif rot == 4
    rot = 'ab';
end
iterate_over_b(rot, as, ae, bs, be, gs, ge)

% Demo of how to use STIR from matlab to display some images 

% Copyright 2012-06-05 - 2013 Kris Thielemans

% This file is part of STIR.
%
% This file is free software; you can redistribute it and/or modify
% it under the terms of the GNU Lesser General Public License as published by
% the Free Software Foundation; either version 2.1 of the License, or
% (at your option) any later version.
%
% This file is distributed in the hope that it will be useful,
% but WITHOUT ANY WARRANTY; without even the implied warranty of
% MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
% GNU Lesser General Public License for more details.
%
% See STIR/LICENSE.txt for details

%% read an image using STIR
image=stir.FloatVoxelsOnCartesianGrid.read_from_file('../../recon_test_pack/test_image_3.hv');

%% convert data to matlab3d array
matimage=image.to_matlab();

%% make some plots
% first a bitmap
figure()
imshow(matimage(:,:,10),[]);
title('slice 10 (starting from 0)')
% now a profile
figure()
plot(matimage(:,45,10));
xlabel('x')
title('slice 10, line 45 (starting from 0)')

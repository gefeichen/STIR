//
// $Id$: $Date$
//


#ifndef _BackProjectorByBinUsingProjMatrixByBin_
#define _BackProjectorByBinUsingProjMatrixByBin_

/*!

  \file

  \brief 

  \author Mustapha Sadki
  \author Kris Thielemans
  \author PARAPET project

  \date $Date$

  \version $Revision$
*/

#include "recon_buildblock/ProjMatrixByBin.h"
#include "recon_buildblock/BackProjectorByBin.h"
#include "tomo/RegisteredParsingObject.h"
#include "shared_ptr.h"
//#include "DataSymmetriesForBins.h"
//#include "RelatedViewgrams.h"

class Viewgrams;
template <typename elemT> class RelatedViewgrams;
class ProjDataInfoCylindricalArcCorr;


START_NAMESPACE_TOMO

/*!
  \brief This implements the BackProjectorByBin interface, given any 
ProjMatrixByBin object
    
  */
class BackProjectorByBinUsingProjMatrixByBin: 
  public RegisteredParsingObject<BackProjectorByBinUsingProjMatrixByBin,
                                 BackProjectorByBin>
{ 
public:
    //! Name which will be used when parsing a BackProjectorByBin object
  static const char * const registered_name; 

  BackProjectorByBinUsingProjMatrixByBin();

  BackProjectorByBinUsingProjMatrixByBin (  
    const shared_ptr<ProjMatrixByBin>& proj_matrix_ptr);

  //! Stores all necessary geometric info
  /*! Note that the density_info_ptr is not stored in this object. It's only used to get some info on sizes etc.
  */
  virtual void set_up(		 
    const shared_ptr<ProjDataInfo>& proj_data_info_ptr,
    const shared_ptr<DiscretisedDensity<3,float> >& density_info_ptr // TODO should be Info only
    );
	 
  const DataSymmetriesForViewSegmentNumbers * get_symmetries_used() const;


  virtual void actual_back_project(DiscretisedDensity<3,float>& image,
                                   const RelatedViewgrams<float>&,
		                   const int min_axial_pos_num, const int max_axial_pos_num,
		                   const int min_tangential_pos_num, const int max_tangential_pos_num);


  shared_ptr<ProjMatrixByBin> &
    get_proj_matrix_sptr(){ return proj_matrix_ptr ;} 
  
  
protected:

  shared_ptr<ProjMatrixByBin> proj_matrix_ptr;

private:
  virtual void set_defaults();
  virtual void initialise_keymap();

};


 

END_NAMESPACE_TOMO

//#include "recon_buildblock/BackProjectorByBinUsingProjMatrixByBin.inl"

#endif



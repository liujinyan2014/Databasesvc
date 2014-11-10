#ifndef IDATABASESVC_H
#define IDATABASESVC_H


 // Base classes
#include"SniperKernel/SvcBase.h"


class IDatabaseSvc : public SvcBase
{
 
  public:
   /* Virtual destructor */
   virtual ~IDatabaseSvc() {};

   virtual bool initialize() =0;

   virtual bool finalize() =0;
 
};
 
#endif

#ifndef DQM_HCALMONITORTASKS_HCALDIGIMONITOR_H
#define DQM_HCALMONITORTASKS_HCALDIGIMONITOR_H

#include "DQM/HcalMonitorTasks/interface/HcalBaseMonitor.h"
#include "DataFormats/HcalDigi/interface/HcalDigiCollections.h"

/** \class HcalDigiMonitor
  *  
  * $Date: 2006/04/04 19:27:03 $
  * $Revision: 1.5 $
  * \author W. Fisher - FNAL
  */
class HcalDigiMonitor: public HcalBaseMonitor {
public:
  HcalDigiMonitor(); 
  ~HcalDigiMonitor(); 

  void setup(const edm::ParameterSet& ps, DaqMonitorBEInterface* dbe);
  void processEvent(const HBHEDigiCollection& hbhe,
		    const HODigiCollection& ho,
		    const HFDigiCollection& hf);

private:  ///Monitoring elements

  void fillErrors(const HBHEDataFrame& hb);
  void fillErrors(const HODataFrame& ho);
  void fillErrors(const HFDataFrame& hf);

  int ievt_;
  MonitorElement* meEVT_;
  
  struct{
    MonitorElement* DIGI_NUM;
    MonitorElement* DIGI_SIZE;
    MonitorElement* DIGI_PRESAMPLE;
    MonitorElement* QIE_CAPID;
    MonitorElement* QIE_ADC;
    MonitorElement* QIE_DV;
    MonitorElement* ERR_MAP_GEO;
    MonitorElement* ERR_MAP_ELEC;
    MonitorElement* OCC_MAP_GEO;
    MonitorElement* OCC_MAP_ELEC;

  } hbHists, hfHists, hoHists;

  int occThresh_;

};

#endif

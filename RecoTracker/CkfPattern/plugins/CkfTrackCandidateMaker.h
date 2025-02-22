#ifndef CkfTrackCandidateMaker_h
#define CkfTrackCandidateMaker_h

#include "FWCore/Framework/interface/stream/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "TrackingTools/TrajectoryCleaning/interface/TrajectoryCleaner.h"

#include "MagneticField/Engine/interface/MagneticField.h"
#include "TrackingTools/DetLayers/interface/NavigationSchool.h"
#include "RecoTracker/TkDetLayers/interface/GeometricSearchTracker.h"

#include "RecoTracker/CkfPattern/interface/RedundantSeedCleaner.h"
#include "RecoTracker/CkfPattern/interface/CkfTrackCandidateMakerBase.h"
#include "DataFormats/TrackCandidate/interface/TrackCandidateCollection.h"
#include "DataFormats/TrackReco/interface/SeedStopInfo.h"

class TransientInitialStateEstimator;

namespace cms {
  class dso_internal CkfTrackCandidateMaker : public edm::stream::EDProducer<>, public CkfTrackCandidateMakerBase {
  public:
    explicit CkfTrackCandidateMaker(const edm::ParameterSet& conf)
        : CkfTrackCandidateMakerBase(conf, consumesCollector()) {
      produces<TrackCandidateCollection>();
      produces<std::vector<SeedStopInfo> >();
    }

    ~CkfTrackCandidateMaker() override { ; }

    void beginRun(edm::Run const& r, edm::EventSetup const& es) override { beginRunBase(r, es); }

    void produce(edm::Event& e, const edm::EventSetup& es) override { produceBase(e, es); }
  };
}  // namespace cms

#endif

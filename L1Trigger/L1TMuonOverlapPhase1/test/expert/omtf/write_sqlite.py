import FWCore.ParameterSet.Config as cms

process = cms.Process("TEST")
process.load("CondCore.CondDB.CondDB_cfi")
process.CondDB.connect = 'sqlite_file:Patterns.db'

process.source = cms.Source("EmptyIOVSource",
    lastValue = cms.uint64(1),
    timetype = cms.string('runnumber'),
    firstValue = cms.uint64(1),
    interval = cms.uint64(1)
)

process.PoolDBOutputService = cms.Service("PoolDBOutputService",
    process.CondDB,
    timetype = cms.untracked.string('runnumber'),
    toPut = cms.VPSet(cms.PSet(
                      record = cms.string('L1TMTFOverlapParamsRcd'),
                      tag = cms.string('params')),
                      cms.PSet(
                      record = cms.string('L1TMTFOverlapParamsRcd'),
                      tag = cms.string('patterns'))
    )
)

###OMTF CondFormats ESProducer
process.load('L1Trigger.L1TMuonOverlapPhase1.fakeOmtfParams_cff')

###EDAnalyzer writing the OMTFParams objects to sqlite file
process.write_sqlite = cms.EDAnalyzer("L1MuonOverlapPhase1ParamsDBProducer")

process.p = cms.Path(process.write_sqlite)

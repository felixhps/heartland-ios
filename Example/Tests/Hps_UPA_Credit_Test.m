#import <XCTest/XCTest.h>
#import "HpsUpaDevice.h"
#import "HpsUpaAuthBuilder.h"
#import "HpsUpaAdjustBuilder.h"
#import "HpsUpaCaptureBuilder.h"
#import "HpsUpaReturnBuilder.h"
#import "HpsUpaReversalBuilder.h"
#import "HpsUpaSaleBuilder.h"
#import "HpsUpaVerifyBuilder.h"
#import "HpsUpaVoidBuilder.h"

@interface Hps_Upa_Credit_Tests : XCTestCase

@end

@implementation Hps_Upa_Credit_Tests
- (HpsUpaDevice*) setupDevice
{
    HpsConnectionConfig *config = [[HpsConnectionConfig alloc] init];
    config.username = @"701420636";
    config.password = @"$Test1234";
    config.licenseID = @"145801";
    config.siteID = @"145898";
    config.deviceID = @"90916202";
    config.ipAddress = @"192.168.0.27";
    config.port = @"8081";
    config.connectionMode = HpsConnectionModes_TCP_IP;
    HpsUpaDevice * device = [[HpsUpaDevice alloc] initWithConfig:config];
    return device;
}

- (void)setUp {
    [self setContinueAfterFailure:NO];
    sleep(10);
}

- (void) test_UPA_Sale
{
    XCTestExpectation *expectation = [self expectationWithDescription:@"test_UPA_Sale"];
    
    HpsUpaDevice *device = [self setupDevice];
    HpsUpaSaleBuilder* builder = [[HpsUpaSaleBuilder alloc] initWithDevice:device];
    builder.ecrId = @"3";
    builder.amount = [[NSDecimalNumber alloc] initWithDouble:5];
    builder.gratuity = [[NSDecimalNumber alloc] initWithDouble:0];

    [builder execute:^(HpsUpaResponse * response, NSError * error) {
        XCTAssertNil(error);
        XCTAssertNotNil(response);
        XCTAssertTrue([response.result isEqualToString:@"Success"]);
        XCTAssertTrue([response.responseCode isEqualToString:@"00"]);
        XCTAssertNotNil(response.transactionId);
        XCTAssertNil(response.deviceResponseCode);
        XCTAssertNil(response.deviceResponseMessage);
        [expectation fulfill];
    }];
    
    [self waitForExpectationsWithTimeout:60.0 handler:^(NSError *error) {
        if(error) XCTFail(@"Request Timed out");
    }];
}

- (void) test_UPA_Sale_Void
{
    XCTestExpectation *expectation = [self expectationWithDescription:@"test_UPA_Sale_Void"];
    
    HpsUpaDevice *device = [self setupDevice];
    HpsUpaSaleBuilder *builder = [[HpsUpaSaleBuilder alloc] initWithDevice:device];
    builder.amount = [[NSDecimalNumber alloc] initWithDouble:1.00];
    builder.gratuity = [[NSDecimalNumber alloc] initWithDouble:0.00];
    builder.ecrId = @"1";
    
    [builder execute:^(HpsUpaResponse *payload, NSError *error) {
        XCTAssertNil(error);
        XCTAssertEqualObjects(@"00", payload.responseCode);
        XCTAssertNotNil(payload);
     
        sleep(1);
        
        //Void
        HpsUpaVoidBuilder *vbuilder = [[HpsUpaVoidBuilder alloc] initWithDevice:device];
        vbuilder.ecrId = @"1";
        vbuilder.terminalRefNumber = payload.terminalRefNumber;
        
        [vbuilder execute:^(HpsUpaResponse *vpayload, NSError *verror) {
            XCTAssertNil(verror);
            XCTAssertEqualObjects(@"00", vpayload.responseCode);
            XCTAssertNotNil(vpayload);
            [expectation fulfill];
        }];
    }];
    
    [self waitForExpectationsWithTimeout:120.0 handler:^(NSError *error) {
        if(error) XCTFail(@"Request Timed out");
    }];
}

- (void) test_UPA_Sale_Refund
{
    XCTestExpectation *expectation = [self expectationWithDescription:@"test_UPA_Sale_Refund"];
    
    HpsUpaDevice *device = [self setupDevice];
    HpsUpaSaleBuilder *builder = [[HpsUpaSaleBuilder alloc] initWithDevice:device];
    builder.amount = [[NSDecimalNumber alloc] initWithDouble:1.00];
    builder.gratuity = [[NSDecimalNumber alloc] initWithDouble:0.00];
    builder.ecrId = @"1";
    
    [builder execute:^(HpsUpaResponse *payload, NSError *error) {
        XCTAssertNil(error);
        XCTAssertEqualObjects(@"00", payload.responseCode);
        XCTAssertNotNil(payload);
     
        sleep(1);
        
        //Refund
        HpsUpaReturnBuilder *rbuilder = [[HpsUpaReturnBuilder alloc] initWithDevice:device];
        rbuilder.ecrId = @"1";
        rbuilder.amount = [[NSDecimalNumber alloc] initWithDouble:1.00];
        
        [rbuilder execute:^(HpsUpaResponse *rpayload, NSError *rerror) {
            XCTAssertNil(rerror);
            XCTAssertEqualObjects(@"00", rpayload.responseCode);
            XCTAssertNotNil(rpayload);
            [expectation fulfill];
        }];
    }];
    
    [self waitForExpectationsWithTimeout:120.0 handler:^(NSError *error) {
        if(error) XCTFail(@"Request Timed out");
    }];
}

- (void) test_UPA_Sale_Adjust
{
    XCTestExpectation *expectation = [self expectationWithDescription:@"test_UPA_Sale_Adjust"];
    
    HpsUpaDevice *device = [self setupDevice];
    HpsUpaSaleBuilder *builder = [[HpsUpaSaleBuilder alloc] initWithDevice:device];
    builder.amount = [[NSDecimalNumber alloc] initWithDouble:1.00];
    builder.gratuity = [[NSDecimalNumber alloc] initWithDouble:0.00];
    builder.ecrId = @"1";
    
    [builder execute:^(HpsUpaResponse *payload, NSError *error) {
        XCTAssertNil(error);
        XCTAssertEqualObjects(@"00", payload.responseCode);
        XCTAssertNotNil(payload);
     
        sleep(1);
        
        //Adjust
        HpsUpaAdjustBuilder *abuilder = [[HpsUpaAdjustBuilder alloc] initWithDevice:device];
        abuilder.ecrId = @"1";
        abuilder.gratuity = [[NSDecimalNumber alloc] initWithDouble:1.00];
        abuilder.terminalRefNumber = payload.terminalRefNumber;
        
        [abuilder execute:^(HpsUpaResponse *apayload, NSError *aerror) {
            XCTAssertNil(aerror);
            XCTAssertEqualObjects(@"00", apayload.responseCode);
            XCTAssertNotNil(apayload);
            [expectation fulfill];
        }];
    }];
    
    [self waitForExpectationsWithTimeout:120.0 handler:^(NSError *error) {
        if(error) XCTFail(@"Request Timed out");
    }];
}

- (void) test_UPA_Sale_Reversal
{
    XCTestExpectation *expectation = [self expectationWithDescription:@"test_UPA_Sale_Reversal"];
    
    HpsUpaDevice *device = [self setupDevice];
    HpsUpaSaleBuilder *builder = [[HpsUpaSaleBuilder alloc] initWithDevice:device];
    builder.amount = [[NSDecimalNumber alloc] initWithDouble:1.00];
    builder.gratuity = [[NSDecimalNumber alloc] initWithDouble:0.00];
    builder.ecrId = @"1";
    
    [builder execute:^(HpsUpaResponse *payload, NSError *error) {
        XCTAssertNil(error);
        XCTAssertEqualObjects(@"00", payload.responseCode);
        XCTAssertNotNil(payload);
     
        sleep(1);
        
        //Reversal
        HpsUpaReversalBuilder *rbuilder = [[HpsUpaReversalBuilder alloc] initWithDevice:device];
        rbuilder.ecrId = @"1";
        rbuilder.terminalRefNumber = payload.terminalRefNumber;
        
        [rbuilder execute:^(HpsUpaResponse *rpayload, NSError *rerror) {
            XCTAssertNil(rerror);
            XCTAssertEqualObjects(@"00", rpayload.responseCode);
            XCTAssertNotNil(rpayload);
            [expectation fulfill];
        }];
    }];
    
    [self waitForExpectationsWithTimeout:120.0 handler:^(NSError *error) {
        if(error) XCTFail(@"Request Timed out");
    }];
}

- (void) test_UPA_Adjust_Reversal
{
    XCTestExpectation *expectation = [self expectationWithDescription:@"test_UPA_Adjust_Reversal"];
    
    HpsUpaDevice *device = [self setupDevice];
    HpsUpaSaleBuilder *builder = [[HpsUpaSaleBuilder alloc] initWithDevice:device];
    builder.amount = [[NSDecimalNumber alloc] initWithDouble:1.00];
    builder.gratuity = [[NSDecimalNumber alloc] initWithDouble:0.00];
    builder.ecrId = @"1";
    
    [builder execute:^(HpsUpaResponse *payload, NSError *error) {
        XCTAssertNil(error);
        XCTAssertEqualObjects(@"00", payload.responseCode);
        XCTAssertNotNil(payload);
        
        sleep(1);
        
        //Adjust
        HpsUpaAdjustBuilder *abuilder = [[HpsUpaAdjustBuilder alloc] initWithDevice:device];
        abuilder.ecrId = @"1";
        abuilder.gratuity = [[NSDecimalNumber alloc] initWithDouble:1.00];
        abuilder.terminalRefNumber = payload.terminalRefNumber;
        
        [abuilder execute:^(HpsUpaResponse *apayload, NSError *aerror) {
            XCTAssertNil(aerror);
            XCTAssertEqualObjects(@"00", apayload.responseCode);
            XCTAssertNotNil(apayload);
     
            sleep(1);
            
            //Reversal
            HpsUpaReversalBuilder *rbuilder = [[HpsUpaReversalBuilder alloc] initWithDevice:device];
            rbuilder.ecrId = @"1";
            rbuilder.terminalRefNumber = payload.terminalRefNumber;
            
            [rbuilder execute:^(HpsUpaResponse *rpayload, NSError *rerror) {
                XCTAssertNil(rerror);
                XCTAssertEqualObjects(@"00", rpayload.responseCode);
                XCTAssertNotNil(rpayload);
                [expectation fulfill];
            }];
        }];
    }];
    
    [self waitForExpectationsWithTimeout:120.0 handler:^(NSError *error) {
        if(error) XCTFail(@"Request Timed out");
    }];
}

- (void) test_UPA_Auth_Capture
{
    XCTestExpectation *expectation = [self expectationWithDescription:@"test_UPA_Auth_Capture"];
    
    HpsUpaDevice *device = [self setupDevice];
    HpsUpaAuthBuilder *builder = [[HpsUpaAuthBuilder alloc] initWithDevice:device];
    builder.amount = [[NSDecimalNumber alloc] initWithDouble:1.00];
    builder.ecrId = @"1";
    
    [builder execute:^(HpsUpaResponse *payload, NSError *error) {
        XCTAssertNil(error);
        XCTAssertEqualObjects(@"00", payload.responseCode);
        XCTAssertNotNil(payload);
        
        sleep(5);
     
        //Capture
        HpsUpaCaptureBuilder *cbuilder = [[HpsUpaCaptureBuilder alloc] initWithDevice:device];
        cbuilder.issuerRefNumber = payload.issuerRefNumber;
        cbuilder.amount = [[NSDecimalNumber alloc] initWithDouble:15.00];
        cbuilder.gratuity = [[NSDecimalNumber alloc] initWithDouble:0.00];
        cbuilder.ecrId = @"1";
        
        [cbuilder execute:^(HpsUpaResponse *cpayload, NSError *cerror) {
            XCTAssertNil(cerror);
            XCTAssertEqualObjects(@"00", cpayload.responseCode);
            XCTAssertNotNil(cpayload);
            [expectation fulfill];
        }];
    }];
    
    [self waitForExpectationsWithTimeout:120.0 handler:^(NSError *error) {
        if(error) XCTFail(@"Request Timed out");
    }];
}

- (void) test_UPA_Auth_Void
{
    XCTestExpectation *expectation = [self expectationWithDescription:@"test_UPA_Auth_Void"];
    
    HpsUpaDevice *device = [self setupDevice];
    HpsUpaAuthBuilder *builder = [[HpsUpaAuthBuilder alloc] initWithDevice:device];
    builder.amount = [[NSDecimalNumber alloc] initWithDouble:1.00];
    builder.ecrId = @"1";
    
    [builder execute:^(HpsUpaResponse *payload, NSError *error) {
        XCTAssertNil(error);
        XCTAssertEqualObjects(@"00", payload.responseCode);
        XCTAssertNotNil(payload);
        
        sleep(1);
     
        //Void
        HpsUpaVoidBuilder *vbuilder = [[HpsUpaVoidBuilder alloc] initWithDevice:device];
        vbuilder.ecrId = @"1";
        vbuilder.issuerRefNumber = payload.issuerRefNumber;
        
        [vbuilder execute:^(HpsUpaResponse *vpayload, NSError *verror) {
            XCTAssertNil(verror);
            XCTAssertEqualObjects(@"00", vpayload.responseCode);
            XCTAssertNotNil(vpayload);
            [expectation fulfill];
        }];
    }];
    
    [self waitForExpectationsWithTimeout:120.0 handler:^(NSError *error) {
        if(error) XCTFail(@"Request Timed out");
    }];
}

- (void) test_UPA_Auth_Reversal
{
    XCTestExpectation *expectation = [self expectationWithDescription:@"test_UPA_Auth_Reversal"];
    
    HpsUpaDevice *device = [self setupDevice];
    HpsUpaAuthBuilder *builder = [[HpsUpaAuthBuilder alloc] initWithDevice:device];
    builder.amount = [[NSDecimalNumber alloc] initWithDouble:1.00];
    builder.ecrId = @"1";
    
    [builder execute:^(HpsUpaResponse *payload, NSError *error) {
        XCTAssertNil(error);
        XCTAssertEqualObjects(@"00", payload.responseCode);
        XCTAssertNotNil(payload);
     
        sleep(1);
        
        //Reversal
        HpsUpaReversalBuilder *rbuilder = [[HpsUpaReversalBuilder alloc] initWithDevice:device];
        rbuilder.ecrId = @"1";
        rbuilder.terminalRefNumber = payload.terminalRefNumber;
        
        [rbuilder execute:^(HpsUpaResponse *rpayload, NSError *rerror) {
            XCTAssertNil(rerror);
            XCTAssertEqualObjects(@"00", rpayload.responseCode);
            XCTAssertNotNil(rpayload);
            [expectation fulfill];
        }];
    }];
    
    [self waitForExpectationsWithTimeout:120.0 handler:^(NSError *error) {
        if(error) XCTFail(@"Request Timed out");
    }];
}


- (void) test_UPA_Verify
{
    XCTestExpectation *expectation = [self expectationWithDescription:@"test_UPA_Verify"];
    
    HpsUpaDevice *device = [self setupDevice];
    HpsUpaVerifyBuilder* builder = [[HpsUpaVerifyBuilder alloc] initWithDevice:device];
    builder.ecrId = @"3";
    builder.requestMultiUseToken = true;

    [builder execute:^(HpsUpaResponse * response, NSError * error) {
        XCTAssertNil(error);
        XCTAssertNotNil(response);
        XCTAssertTrue([response.result isEqualToString:@"Success"]);
        XCTAssertTrue([response.responseCode isEqualToString:@"00"]);
        XCTAssertNotNil(response.transactionId);
        XCTAssertNotNil(response.tokenData);
        XCTAssertNotNil(response.tokenData.tokenValue);
        XCTAssertNil(response.deviceResponseCode);
        XCTAssertNil(response.deviceResponseMessage);
        [expectation fulfill];
    }];
    
    [self waitForExpectationsWithTimeout:60.0 handler:^(NSError *error) {
        if(error) XCTFail(@"Request Timed out");
    }];
}

- (void) test_UPA_Refund
{
    XCTestExpectation *expectation = [self expectationWithDescription:@"test_UPA_Refund"];
    
    HpsUpaDevice *device = [self setupDevice];
    HpsUpaReturnBuilder *builder = [[HpsUpaReturnBuilder alloc] initWithDevice:device];
    builder.amount = [[NSDecimalNumber alloc] initWithDouble:1.00];
    builder.ecrId = @"1";
    
    [builder execute:^(HpsUpaResponse *payload, NSError *error) {
        XCTAssertNil(error);
        XCTAssertEqualObjects(@"00", payload.responseCode);
        XCTAssertNotNil(payload);
        [expectation fulfill];
    }];
    
    [self waitForExpectationsWithTimeout:120.0 handler:^(NSError *error) {
        if(error) XCTFail(@"Request Timed out");
    }];
}

- (void) test_UPA_Refund_Void
{
    XCTestExpectation *expectation = [self expectationWithDescription:@"test_UPA_Refund_Void"];
    
    HpsUpaDevice *device = [self setupDevice];
    HpsUpaReturnBuilder *builder = [[HpsUpaReturnBuilder alloc] initWithDevice:device];
    builder.amount = [[NSDecimalNumber alloc] initWithDouble:1.00];
    builder.ecrId = @"1";
    
    [builder execute:^(HpsUpaResponse *payload, NSError *error) {
        XCTAssertNil(error);
        XCTAssertEqualObjects(@"00", payload.responseCode);
        XCTAssertNotNil(payload);
     
        sleep(1);
        
        //Void
        HpsUpaVoidBuilder *vbuilder = [[HpsUpaVoidBuilder alloc] initWithDevice:device];
        vbuilder.ecrId = @"1";
        vbuilder.terminalRefNumber = payload.terminalRefNumber;
        
        [vbuilder execute:^(HpsUpaResponse *vpayload, NSError *verror) {
            XCTAssertNil(verror);
            XCTAssertEqualObjects(@"00", vpayload.responseCode);
            XCTAssertNotNil(vpayload);
            [expectation fulfill];
        }];
    }];
    
    [self waitForExpectationsWithTimeout:120.0 handler:^(NSError *error) {
        if(error) XCTFail(@"Request Timed out");
    }];
}

- (void) test_UPA_Refund_Reversal
{
    XCTestExpectation *expectation = [self expectationWithDescription:@"test_UPA_Refund_Reversal"];
    
    HpsUpaDevice *device = [self setupDevice];
    HpsUpaReturnBuilder *builder = [[HpsUpaReturnBuilder alloc] initWithDevice:device];
    builder.amount = [[NSDecimalNumber alloc] initWithDouble:1.00];
    builder.ecrId = @"1";
    
    [builder execute:^(HpsUpaResponse *payload, NSError *error) {
        XCTAssertNil(error);
        XCTAssertEqualObjects(@"00", payload.responseCode);
        XCTAssertNotNil(payload);
     
        sleep(1);
        
        //Reversal
        HpsUpaReversalBuilder *rbuilder = [[HpsUpaReversalBuilder alloc] initWithDevice:device];
        rbuilder.ecrId = @"1";
        rbuilder.terminalRefNumber = payload.terminalRefNumber;
        
        [rbuilder execute:^(HpsUpaResponse *rpayload, NSError *rerror) {
            XCTAssertNil(rerror);
            XCTAssertEqualObjects(@"00", rpayload.responseCode);
            XCTAssertNotNil(rpayload);
            [expectation fulfill];
        }];
    }];
    
    [self waitForExpectationsWithTimeout:120.0 handler:^(NSError *error) {
        if(error) XCTFail(@"Request Timed out");
    }];
}


@end


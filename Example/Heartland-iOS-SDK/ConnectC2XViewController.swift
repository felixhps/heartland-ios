//
//  ConnectC2XViewController.swift
//

import Foundation
import UIKit
import Heartland_iOS_SDK
import CoreBluetooth

class ConnectC2XViewController: UIViewController {
    
    var device: HpsC2xDevice?
    private let notificationCenter: NotificationCenter = NotificationCenter.default
    
    @IBOutlet var connectionLabel: UILabel!
    @IBOutlet var activityIndicator: UIActivityIndicatorView!
    @IBOutlet weak var scanButton: UIStackView!
    
    @IBAction func scanButtonPressed() {
        
        let timeout = 120
        let timeoutPoint = UnsafeMutablePointer<Int>.allocate(capacity: 1)
        timeoutPoint.initialize(to: timeout)
        
        let config = HpsConnectionConfig()
        config.username = "703674685"
        config.password = "$Test1234"
        config.siteID = "372880";
        config.deviceID = "90915912"
        config.licenseID = "372711"
        config.developerID = "002914"
        config.versionNumber = "3409"
        config.timeout = timeoutPoint
        
        self.device = HpsC2xDevice(config: config)
        self.device?.deviceDelegate = self
        self.device?.scan()
        self.activityIndicator.isHidden = false
    }
}

extension ConnectC2XViewController: HpsC2xDeviceDelegate {
    func onConnected() {
        self.connectionLabel.text = "Connected"
        
        let selectedDevice:[String: HpsC2xDevice?] = ["selectedDevice": self.device]
        notificationCenter.post(name: Notification.Name(Constants.selectedDeviceNotification),
                                object: nil, userInfo: selectedDevice)
    }
    
    func onDisconnected() {
        self.connectionLabel.text = "Disconnected"
    }
    
    func onError(_ deviceError: NSError) {
        self.connectionLabel.text = "Error"
    }
    
    func onBluetoothDeviceList(_ peripherals: NSMutableArray) {
        
        let alertController = UIAlertController(title: "Devices", message: "Please select a device to connect", preferredStyle: .actionSheet)
        
        for peripheral in peripherals {
            if let peripheral = peripheral as? HpsTerminalInfo {
                let action = UIAlertAction(title: peripheral.name, style: .default) { [weak self] _ in
                    self?.device?.connectDevice(peripheral)
                }
                alertController.addAction(action)
            }
        }
        
        let cancelAction = UIAlertAction(title: "Cancel", style: .destructive)
        alertController.addAction(cancelAction)
        if case .pad = UIDevice.current.userInterfaceIdiom {
            alertController.popoverPresentationController?.sourceView = scanButton
            alertController.popoverPresentationController?.sourceRect = scanButton.bounds
            alertController.popoverPresentationController?.permittedArrowDirections = .down
        }
        self.present(alertController, animated: true)
        
        self.activityIndicator.isHidden = true
    }
}

// MARK: - IDIOM

private extension ConnectC2XViewController {
    enum UIUserInterfaceIdiom : Int {
        case phone // iPhone and iPod touch style UI
        case pad   // iPad style UI (also includes macOS Catalyst)
    }
}

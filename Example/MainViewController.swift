//
//  MainViewController.swift
//

import UIKit

class MainViewController: UITableViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        navigationController?.pushViewController(C2XTransactionsViewController(),
                                                 animated: true)
    }


}


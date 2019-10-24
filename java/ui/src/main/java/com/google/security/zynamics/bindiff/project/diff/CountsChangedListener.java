package com.google.security.zynamics.bindiff.project.diff;

/**
 * Base class for change listeners that listen for changes in the number of diff entities. This
 * avoids having empty implementations scattered all over the code base.
 *
 * @author cblichmann@google.com (Christian Blichmann)
 */
public class CountsChangedListener {
  public void basicBlocksCountChanged() {
    // Do nothing by default
  }

  public void callsCountChanged() {
    // Do nothing by default
  }

  public void functionsCountChanged() {
    // Do nothing by default
  }

  public void instructionsCountsChanged() {
    // Do nothing by default
  }

  public void jumpsCountChanged() {
    // Do nothing by default
  }
}
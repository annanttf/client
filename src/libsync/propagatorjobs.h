/*
 * Copyright (C) by Olivier Goffart <ogoffart@owncloud.com>
 * Copyright (C) by Klaas Freitag <freitag@owncloud.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 */

#pragma once

#include "owncloudpropagator.h"
#include <QFile>
#include <qdebug.h>

namespace OCC {

class PropagateLocalRemove : public PropagateItemJob {
    Q_OBJECT
public:
    PropagateLocalRemove (OwncloudPropagator* propagator,const SyncFileItem& item)  : PropagateItemJob(propagator, item) {}
    void start() Q_DECL_OVERRIDE;
};
class PropagateLocalMkdir : public PropagateItemJob {
    Q_OBJECT
public:
    PropagateLocalMkdir (OwncloudPropagator* propagator,const SyncFileItem& item)  : PropagateItemJob(propagator, item) {}
    void start() Q_DECL_OVERRIDE;

};
class PropagateLocalRename : public PropagateItemJob {
    Q_OBJECT
public:
    PropagateLocalRename (OwncloudPropagator* propagator,const SyncFileItem& item)  : PropagateItemJob(propagator, item) {}
    void start() Q_DECL_OVERRIDE;
    JobParallelism parallelism() Q_DECL_OVERRIDE { return WaitForFinishedInParentDirectory; }
};


}

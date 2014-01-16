#import "NMSSH.h"

/**
 The NMSFTPFile class provides an interface to store file attributes retrieved 
 from a SFTP host.
 */
@interface NMSFTPFile : NSObject

/**
 Property that stores the name of the underlaying file. 
 Note that the file may also be a directory.
 */
@property (nonatomic, readonly, strong) NSString* filename;

/** Property that declares whether the file is a directory or a regular file */
@property (nonatomic, readonly) BOOL isDirectory;

/** Returns the last modification date of the file */
@property (nonatomic, readonly ,strong) NSDate* modificationDate;

/** Returns the date of the last access to the file */
@property (nonatomic, readonly ,strong) NSDate* lastAccess;

/** Property that returns the file size in bytes */
@property (nonatomic, readonly, strong) NSNumber* fileSize;

/** Returns the numeric identifier of the user that is the owner of the file */
@property (nonatomic, readonly) uid_t ownerUserID;

/** Returns the numeric identifier of the group that is the owner of the file */
@property (nonatomic, readonly) gid_t ownerGroupID;

/** Returns the file permissions in symbolic notation. E.g. drwxr-xr-x */
@property (nonatomic, readonly, strong) NSString* permissions;

/** Returns the user defined flags for the file */
@property (nonatomic, readonly) u_long flags;


/**
 Initializes an NMSFTPFile instance and sets the filename.
 
 @param filename The name of the underlaying file.
 @return A new NMSFTPFile instance initialized with the corresponding filename.
 */
- (instancetype)initWithFilename:(NSString*)filename;

/**
 Populates the file properties with the attributes taken from the LIBSSH2_SFTP_ATTRIBUTES object.
 
 @param fileAttributes The LIBSSH2_SFTP_ATTRIBUTES object that contains the attributes that are being extracted.
 */
- (void)populateValuesFromSFTPAttributes:(LIBSSH2_SFTP_ATTRIBUTES)fileAttributes;

@end
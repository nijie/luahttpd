#!/usr/bin/perl -W
#
# Copyright (c) 2014 Nijie. All rights reserved.
# License: GPL-2
#
# File: comments.pl  用于增加c/c++文件注释
# Create by Nijie 2014.07.23
#

use strict;
use warnings;
use File::Copy;

my $author='Nijie';			# 作者 - 需修改
my $createyear='2014';		# 版权时间 - 需修改
my $date="2014.07.23";		# 文件创建时间 - 需修改

# 以下版权信息 - 需修改
my $comments="// Created by $author on $date.
// Copyright (c) $createyear $author. All rights reserved.
// Use of this source code is governed by a GPL-2 license that can be found in the LICENSE file. 
//
";

my @filterDir = ("./lib3rd/");	# 需要过滤的文件，比如不属于你开发的目录等 - 需修改

my %filterList = ();
foreach (@filterDir)
{
	$filterList{$_} = 1;
}

my ($dircnt, $filecnt) = (0, 0);

sub lsr_s($) {
    my $cwd = shift;
    my @dirs = ($cwd.'/');

    my ($dir, $file);
    while ($dir = pop(@dirs)) {
		if (exists($filterList{$dir}))
		{
			print "skip dir : $dir\n";
			next;
		}
        local *DH;
		print "open $dir\n";
        if (!opendir(DH, $dir)) {
            warn "Cannot opendir $dir: $! $^E";
            next;
        }
        foreach (readdir(DH)) {
            if ($_ eq '.' || $_ eq '..') {
                next;
            }
            $file = $dir.$_;         
            if (!-l $file && -d _) {
                $file .= '/';
                push(@dirs, $file);
            }
            process($file, $dir);
        }
        closedir(DH);
    }
}

sub process($) {
    my $file = shift;
    print "process $file";
    if (substr($file, length($file)-1, 1) eq '/') {
        $dircnt++;
    }
    else {
        $filecnt++;
        if ($file =~ /\.(h$|c$|cpp$|hpp$|cc$)/)
        {
            addComments($file);
        }
    }
    print "\n";
}

sub addComments($)
{
	my $line = 0;
	my $file = shift;
	open FILE, $file or die 'die ($!)';
	open OUTFILE, ">$file~~~" or die "Open the file $file~~~ failed!\n";

	print OUTFILE $comments;
	while (<FILE>)
    {
		print OUTFILE $_;
    }
	close FILE;
	close OUTFILE;
	move("$file~~~", $file);
}

lsr_s('.');
print "$filecnt files, $dircnt directory.\n";
`pause`;


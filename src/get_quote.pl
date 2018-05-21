# 檢查程式中 u"xxx" 的 u 是否有使用, 尤其是漢字部份

use utf8;
use strict;

my @files = <"*.cpp">;

foreach my $file(@files)
{
    #print $file . "\n";
    check($file);
}

sub check
{
    local $_;
    my $file = shift;

    open IN, $file;
    my $count = 0;
    my $innote = 0;
    while(<IN>)
    {
        $count++;
        my $line = $_;

        
        s/\/\/.*//g;
        s/\\"//g;
        s/\\'//g;

        s/\/\*.*?\*\///; # 移除單行註解

        if(/\*\//)
        {
            s/^.*?\*\///;
            $innote = 0;
        }
        elsif(/\/\*/)
        {
            s/\/\*.*//;
            $innote = 1;
        }
        elsif($innote == 1)
        {
            $_ = "";
        }

        while(/.".*?"/)
        {
            s/(.".*?")//;
            my $str = $1;
            if($str !~ /^u"/)
            {
                $str =~ s/^."(.*)"$/$1/;
                $str =~ s/[\s0-9a-zA-Z<>\.\*=\\\/#_\-:;\?\+\(\)\{\}\[\],\^]//ig;

                if($str ne "")
                {
                    print "$file : $count : $str : $line";
                }
            }
        }

        # 查 showmessage
        $_ = $line;
        s/TDialogService::ShowMessage//g;
        s/IsShowMessage//g;
        if(/ShowMessage/)
        {
            print "$file : $count : $line";
        }

    }
}



